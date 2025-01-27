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

// TODO: JUST CODE HERE
void solver(){
    int input(n);
    
    string bits = "";
    for (int i = 0; i < n; i++) bits += '0';
    debug(bits);
    int two_pow_n = 1;
    for (int i = 0; i < n; i++) two_pow_n *= 2;
    debug(two_pow_n);
    for (int i = 1; i < two_pow_n; i++){
        cout<<bits<<nl;
        if(i & 1){
            bits[n-1] = bits[n-1] == '0' ? '1' : '0';
        }else{
            // debug(i & ~(i - 1)); // NOTE: https://medium.com/@manishsakariya/finding-position-of-first-least-significant-non-zero-bit-in-binary-number-6df144602f89
            int binaryNumber = i & ~(i - 1);
            int flip = 0;
            // Find the position of the highest set bit (2^n)
            while (binaryNumber >>= 1) {
                flip++;
            }
            debug(i);
            debug(flip);
            bits[flip-1] = bits[flip-1] == '0' ? '1' : '0';
        }
    }
    cout<<bits<<nl;
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
    It(1){
        tin.set("1");
        solver();
        asserttout(
            "0",
            "1\n"
        );
    }
    It(2){
        tin.set("2");
        solver();
        asserttout(
            "00",
            "01",
            "11",
            "10\n"
        );
    }
    It(3){
        tin.set("3");
        solver();
        asserttout(
            "000",
            "001",
            "011",
            "010",
            "110",
            "111",
            "101",
            "100\n"
        );
    }
    It(4){
        tin.set("4");
        solver();
        asserttout(
            "0000",
            "0001",
            "0011",
            "0010",
            
            "0110",
            "0111",
            "0101",
            "0100",

            "1100",
            "1101",
            "1111",
            "1110",

            "1010",
            "1011",
            "1001",
            "1000\n"
        );
    }
}
#endif