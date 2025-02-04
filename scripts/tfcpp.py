import subprocess
import os
import shutil
import argparse
from typing import List, Tuple
import json
import base64

class JoinPath(str):
    def to_list(self) -> List[str]:
        return self.replace('\\', '/').split('/')
    def _pjoin(self, other: str) -> "JoinPath":
        other = other.replace('\\', '/').split('/')
        return JoinPath(os.path.join(self, *other))
    def __truediv__(self, other: str) -> "JoinPath": return self._pjoin(other)
    def __floordiv__(self, other: str) -> "JoinPath": return self._pjoin(other)
    def __matmul__(self, other: str) -> "JoinPath": return self._pjoin(other)
    
root = JoinPath(os.path.dirname(__file__)) @ '..'

def encodeMeta(single_test_case: bool, fmt_imports: List[str], io_files: bool)->str:
    meta = json.dumps({
        'single_test_case': single_test_case,
        'fmt_imports': fmt_imports,
        'io_files': io_files
    })
    # metahash = sha256(meta.encode()).digest().hex()
    encode = base64.urlsafe_b64encode(meta.encode())
    return encode.decode() #bytearray(255 - i for i in bytearray(encode)).hex()
def decodeMeta(metaEncode: str)->Tuple[bool, List[str]]:
    decode = base64.urlsafe_b64decode(metaEncode.encode())
    meta = decode.decode()
    meta = json.loads(meta)    
    return meta['single_test_case'], meta['fmt_imports'], meta['io_files']

def compile_and_run_cpp(filename: str, fmt_imports: List[str], onetestcase: bool = False, io_files: bool = False):
    project_dir = root @ filename
    
    cpp_file = project_dir @ "main.cpp"
    exe_file = project_dir @ "main.exe"
    metaChanged = False
    
    if not os.path.exists(project_dir): 
        create_new_project(filename, fmt_imports=fmt_imports, onetestcase = onetestcase, io_files = io_files)
    else:
        newmeta = '// @ignore tfmeta: ' + encodeMeta(single_test_case=onetestcase, fmt_imports=fmt_imports, io_files=io_files) + '\n'
        with open(cpp_file, "r") as f:
            oldmeta = f.readline()
        if oldmeta.startswith('// @ignore tfmeta: '):
            metaChanged = oldmeta != newmeta
        else:
            print('Warning!!! Old File, migrating to new version [you may have to face some erros related to imports etc]...')
            # with open(cpp_file, "r") as f:
            #     data = f.read()
            # with open(cpp_file, "w") as f:
            #     f.write(newmeta + data)
    
    if metaChanged: 
        print('Warning!!! File meta is Changed...')
        update_project(filename, oldmeta, fmt_imports=fmt_imports, onetestcase=onetestcase, io_files=io_files)
    
    prefix = '/'.join('..' for _ in project_dir.to_list()[len(root.to_list()):])
    
    # Define the paths for FMT headers and the compile command
    FMTDISPLAYPATH_BASE = f"{prefix}/fmt"

    # Command to compile the C++ file using g++
    compile_command = [
        "g++", "-std=c++17", f'-DFMTDISPLAYPATH_BASE={FMTDISPLAYPATH_BASE}', "-DDEBUG", cpp_file, "-o", exe_file
    ]

    try:
        # Compile the C++ code
        print("Compiling C++ code...")
        subprocess.run(compile_command, check=True)
        print("Compilation successful.")

        # Run the executable
        print("Running the executable...")
        subprocess.run([exe_file], check=True, cwd=project_dir)
    except subprocess.CalledProcessError as e:
        print(f"Error occurred during compilation or execution: {e}")
      
def update_project(project_name: str, oldmeta: str, fmt_imports: List[str], onetestcase: bool = False, io_files: bool = False):
    oldmeta = oldmeta.removeprefix('// @ignore tfmeta: ').removesuffix('\n')
    old_onetestcase, old_fmt_imports, old_io_files = decodeMeta(oldmeta)
    project_dir = root @ project_name
    cpp_file = project_dir @ "main.cpp"
    in_file = project_dir @ ".in.txt"
    out_file = project_dir @ ".out.txt"
    # C++ template code
    cpp_code = """int main(){
    #ifdef DEBUG
        fmt::println(ansi::red, "Debugging information: Program running in debug mode.", ansi::reset);
        RUN_TESTS;
        // freopen(".in.txt", "r", stdin); // read from .in.txt
        // freopen(".out.txt", "w", stdout); // write to .out.txt
        {%tftoken%{io_files}%tftoken%}
    #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // unsigned int t;
    // cin >> t;
    // while (t--) solver();
    {%tftoken%{runner}%tftoken%}
    return 0;
}"""
    cpp_code_new = cpp_code.replace('{%tftoken%{runner}%tftoken%}', 'solver();' if onetestcase else 'unsigned int input(t); while (t--) solver();')
    cpp_code_new = cpp_code_new.replace('{%tftoken%{io_files}%tftoken%}', 'freopen(".in.txt", "r", stdin); freopen(".out.txt", "w", stdout);' if io_files else 'return 0;')
    
    cpp_code_old = cpp_code.replace('{%tftoken%{runner}%tftoken%}', 'solver();' if old_onetestcase else 'unsigned int input(t); while (t--) solver();')
    cpp_code_old = cpp_code_old.replace('{%tftoken%{io_files}%tftoken%}', 'freopen(".in.txt", "r", stdin); freopen(".out.txt", "w", stdout);' if old_io_files else 'return 0;')
    
    if io_files:
        if not os.path.exists(in_file):
            with open(in_file, "w") as f: f.write("1")
        if not os.path.exists(out_file):
            with open(out_file, "w") as f: f.write("expected output here")
    else:
        if os.path.exists(in_file):
            with open(in_file, "r") as f: 
                defaultIn = f.read() == "1"
            if defaultIn: os.remove(in_file)
        if os.path.exists(out_file):
            with open(out_file, "r") as f: 
                defaultOut = f.read() == "expected output here"
            if defaultOut: os.remove(out_file)
    
    with open(cpp_file, "r") as f:
        data = f.read()
    data = data.removeprefix('// @ignore tfmeta: ' + oldmeta + '\n').replace(cpp_code_old, cpp_code_new)
    
    cpp_code = """    #ifdef FMTDISPLAYPATH_BASE 
        #define STR(s) #s
        #define XSTR(s) STR(s)
        // #include XSTR(FMTDISPLAYPATH_BASE/display.h)
        // #include XSTR(FMTDISPLAYPATH_BASE/extra.test.assert.h)
        {%tftoken%{import_fmt_xstr}%tftoken%}
    #else
        // #include "fmt/display.h" // https://github.com/thefcraft/fmt-display-cpp/tree/main/fmt
        // #include "fmt/extra.test.assert.h" // https://github.com/thefcraft/fmt-display-cpp/blob/main/test.assert.h
        {%tftoken%{import_fmt}%tftoken%}
    #endif"""
    cpp_code_new = cpp_code.replace('{%tftoken%{import_fmt_xstr}%tftoken%}', '\n\t\t'.join([f"#include XSTR(FMTDISPLAYPATH_BASE/{name})" for name in fmt_imports]))
    cpp_code_new = cpp_code_new.replace('{%tftoken%{import_fmt}%tftoken%}', '\n\t\t'.join([f"#include \"fmt/{name}\"" for name in fmt_imports]))
    cpp_code_old = cpp_code.replace('{%tftoken%{import_fmt_xstr}%tftoken%}', '\n\t\t'.join([f"#include XSTR(FMTDISPLAYPATH_BASE/{name})" for name in old_fmt_imports]))
    cpp_code_old = cpp_code_old.replace('{%tftoken%{import_fmt}%tftoken%}', '\n\t\t'.join([f"#include \"fmt/{name}\"" for name in old_fmt_imports]))
    
    with open(cpp_file, "w") as f:
        newmeta = '// @ignore tfmeta: ' + encodeMeta(single_test_case=onetestcase, fmt_imports=fmt_imports, io_files=io_files) + '\n'
        f.write(newmeta + data.replace(cpp_code_old, cpp_code_new))
        
def create_new_project(project_name: str, fmt_imports: List[str], onetestcase: bool = False, io_files: bool = False):
    # Define directories and file paths for the new project structure
    project_dir = root @ project_name
    if os.path.exists(project_dir):
        print(f"Project {project_name} already exists.")
        return

    print(f"Creating new project: {project_name}")

    # Create project directory and required files
    os.makedirs(project_dir)
    
    cpp_file = project_dir @ "main.cpp"
    in_file = project_dir @ ".in.txt"
    out_file = project_dir @ ".out.txt"

    # C++ template code
    with open(root @ f'public/.template.tcpp', 'r') as f: 
        cpp_code = f.read()
    cpp_code = cpp_code.replace('{%tftoken%{import_fmt_xstr}%tftoken%}', '\n\t\t'.join([f"#include XSTR(FMTDISPLAYPATH_BASE/{name})" for name in fmt_imports]))
    cpp_code = cpp_code.replace('{%tftoken%{import_fmt}%tftoken%}', '\n\t\t'.join([f"#include \"fmt/{name}\"" for name in fmt_imports]))
    cpp_code = cpp_code.replace('{%tftoken%{runner}%tftoken%}', 'solver();' if onetestcase else 'unsigned int input(t); while (t--) solver();')
    cpp_code = cpp_code.replace('{%tftoken%{io_files}%tftoken%}', 'freopen(".in.txt", "r", stdin); freopen(".out.txt", "w", stdout);' if io_files else 'return 0;')
        
    # Create the files
    with open(cpp_file, "w") as f:
        f.write('// @ignore tfmeta: ' + encodeMeta(single_test_case=onetestcase, fmt_imports=fmt_imports, io_files=io_files) + '\n' + cpp_code)
    
    if io_files:
        with open(in_file, "w") as f:
            f.write("1")
        with open(out_file, "w") as f:
            f.write("expected output here")

    print(f"New project created at {project_dir}")

def main():
    parser = argparse.ArgumentParser(description="Compile and run C++ code.")
    subparsers = parser.add_subparsers(dest="command")

    # 'run' command to compile and run
    run_parser = subparsers.add_parser("run", help="Compile and run C++ code")
    run_parser.add_argument("filename", help="The C++ source file to compile")
    
    # 'new' command to create a new project structure
    new_parser = subparsers.add_parser("new", help="Create a new project")
    new_parser.add_argument("project_name", help="The name of the new project")

    args = parser.parse_args()

    if args.command == "run":
        compile_and_run_cpp(args.filename)
    
    elif args.command == "new":
        create_new_project(args.project_name)
    
    else:
        print("Invalid command. Use 'run' or 'new'.")

if __name__ == "__main__":
    # main()
    if not os.path.exists(root @ 'tfcpp.json'): 
        with open(root @ 'tfcpp.json', 'w') as f: json.dump({
                                                                "project_name": "cses/problemset/task/1069",
                                                                "single_test_case": False,
                                                                "fmt_imports": [
		                                                            "display.h",
	                                                            	"extra.test.assert.h"
	                                                            ]
                                                            }, f, indent='\t ')
    with open(root @ 'tfcpp.json', 'r') as f: 
        data = json.load(f)
    filename = data.get("project_name")
    onetestcase = data.get("single_test_case", False)
    fmt_imports = data.get("fmt_imports", ["display.h", "extra.test.assert.h"])
    io_files = data.get("io_files", False)
    assert filename is not None and onetestcase is not None, "tfcpp.json file is corrupted"
    compile_and_run_cpp(filename, onetestcase=onetestcase, fmt_imports=fmt_imports, io_files=io_files)
