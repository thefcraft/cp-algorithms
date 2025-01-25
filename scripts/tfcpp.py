import subprocess
import os
import shutil
import argparse
from typing import List

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
        
def compile_and_run_cpp(filename: str, onetestcase: bool = False):
    project_dir = root @ filename
    if not os.path.exists(project_dir): 
        create_new_project(filename, onetestcase = onetestcase)
    
    cpp_file = project_dir @ "main.cpp"
    exe_file = project_dir @ "main.exe"
    
    prefix = '/'.join('..' for _ in project_dir.to_list()[len(root.to_list()):])
    
    # Define the paths for FMT headers and the compile command
    FMTASSERTPATH = f"{prefix}/fmt/extra.test.assert.h"
    FMTDISPLAYPATH = f"{prefix}/fmt/display.h"

    # Command to compile the C++ file using g++
    compile_command = [
        "g++", "-std=c++17", f'-DFMTASSERTPATH="{FMTASSERTPATH}"', f'-DFMTDISPLAYPATH="{FMTDISPLAYPATH}"', "-DDEBUG", cpp_file, "-o", exe_file
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
        
        
def create_new_project(project_name: str, onetestcase: bool = False):
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
    with open(root @ f'public/.template{".onetestcase" if onetestcase else ""}.cpp', 'r') as f: 
        cpp_code = f.read()

    # Create the files
    with open(cpp_file, "w") as f:
        f.write(cpp_code)
    
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
    if not os.path.exists(root @ 'tfcpp.file'): 
        with open(root @ 'tfcpp.file', 'a'): ...
    with open(root @ 'tfcpp.file', 'r') as f: 
        filename = f.read().replace('\n', '').strip()
    assert filename != '', "tfcpp.file is empty"
    onetestcase = filename.startswith('cses')
    compile_and_run_cpp(filename, onetestcase=onetestcase)
