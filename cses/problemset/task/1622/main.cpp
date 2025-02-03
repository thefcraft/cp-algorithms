// author: [Laksh Kumar Sisodiya](https://github.com/thefcraft)
// please run `git clone https://github.com/thefcraft/fmt-display-cpp.git`
// and then copy pase `test.assert.h` file and `fmt` dir to the current folder
// and rename .cp.base_template.cpp to main.cpp and modify it to make your own template and enjoy :-)
// pase input text in `.in.txt`
// get output inside `.out.txt`


#include <iostream>
// #include <algorithm>
using namespace std;

// copy past it in run.bat
// '''''''''''''''''''''''''''''
// @REM run by `./run.bat`
// @REM run.bat
// @echo off
// g++ -DDEBUG main.cpp -o main
// if %errorlevel% neq 0 (
//     echo Compilation failed!
//     exit /b %errorlevel%
// )
// main.exe
// '''''''''''''''''''''''''''''

// Debugging utilities
#ifdef DEBUG
    #ifdef FMTDISPLAYPATH_BASE 
        #define STR(s) #s
        #define XSTR(s) STR(s)
        #include XSTR(FMTDISPLAYPATH_BASE/display.h)
        #include XSTR(FMTDISPLAYPATH_BASE/extra.test.assert.h)
        #include XSTR(FMTDISPLAYPATH_BASE/extra.array.h)
    #else
        #include "fmt/display.h" // https://github.com/thefcraft/fmt-display-cpp/tree/main/fmt
        #include "fmt/extra.test.assert.h" // https://github.com/thefcraft/fmt-display-cpp/blob/main/test.assert.h
        #include "fmt/extra.array.h"
    #endif
#else
    #define debug(...)
#endif

#define YES "YES"
#define NO "NO"

const char nl = '\n';

// utility functions
namespace utils{
    // define according to your use cases
}

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;

typedef unsigned long long ull;
typedef signed long long ll;

template<typename... Args>
inline void _input(Args&... args) {(std::cin >> ... >> args);} // output same code in O2, and codeforces compile it on O2 so don't worry; you can check my it by, g++ -O2 -S -o t1.s t1.cpp 
#define input(...) __VA_ARGS__; _input(__VA_ARGS__)
#define inputn(x, n) x[n]; for (size_t i = 0; i < n; i++) cin >> x[i]

void permute_str(int freq[26], string &str, int idx = 0){
    if (idx == str.length()) {
        cout<<str<<nl;
        return;
    }
    
    for(int i = 0; i<26; i++) if(freq[i] != 0) {
        str[idx] = 'a' + i;
        freq[i]--;
        permute_str(freq, str, idx+1);
        freq[i]++;
    }
}

// TODO: JUST CODE HERE
void solver(){
    string input(str); 
    int n = str.length();
    int freq[26] = {0};
    for (const auto &c: str) freq[c - 'a']++;
    int total_answers = 1;
    for (int i = 2; i <= n; i++) total_answers *= i; // n <= 8 so we can do this
    for (size_t i = 0; i < 26; i++) for (int j = 2; j <= freq[i]; j++) total_answers /= j;
    cout<<total_answers<<nl;
    debug(fmt::sprint_array(freq, 26));
    permute_str(freq, str);
}

int main(){
    #ifdef DEBUG
        fmt::println(ansi::red, "Debugging information: Program running in debug mode.", ansi::reset);
        RUN_TESTS;
        freopen(".in.txt", "r", stdin); // read from .in.txt
        freopen(".out.txt", "w", stdout); // write to .out.txt
    #endif


    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solver();
}

// sort(a, a+n, greater<int>());
// sort(a, a+n);

#ifdef DEBUG
MAKE_TESTS{
    // you can use this if you want...
    It(sample test case){
        tin.set("aabac");
        solver();
        asserttout(
            "20",
            "aaabc",
            "aaacb",
            "aabac",
            "aabca",
            "aacab",
            "aacba",
            "abaac",
            "abaca",
            "abcaa",
            "acaab",
            "acaba",
            "acbaa",
            "baaac",
            "baaca",
            "bacaa",
            "bcaaa",
            "caaab",
            "caaba",
            "cabaa",
            "cbaaa\n"
        );
    }
}
#endif