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
    #else
        #include "fmt/display.h" // https://github.com/thefcraft/fmt-display-cpp/tree/main/fmt
        #include "fmt/extra.test.assert.h" // https://github.com/thefcraft/fmt-display-cpp/blob/main/test.assert.h
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
    // https://www.youtube.com/watch?v=12Y8OrlRS3U
    ull input(n); 
    cout<<0<<nl;
    for (ull k = 2; k <= n; k++){
        ull total_positions = (k*k) * (k*k - 1) / 2; // k^2 is even or k^2 - 1 is even so we can divide by 2 easily
        // 3*2 blocks => (n-1)*(n-2)
        // 2*3 blocks => (n-2)*(n-1)
        // knights attacking position on each block = 2
        // aka in 3*2 => (0,0)(2,1) + (0,1)(2,0)  and  in 2*3 => (0,0)(2,1) + (0,2)(1,0)   
        ull attackers_positions = 4*(k-1)*(k-2);
        cout<<total_positions - attackers_positions<<nl;
    }
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
    return 0;
}

// sort(a, a+n, greater<int>());
// sort(a, a+n);

#ifdef DEBUG
MAKE_TESTS{
    It(1){
        tin.set(1);
        solver();
        asserttout("0\n");
    }
    It(2){
        tin.set(2);
        solver();
        asserttout("0", "6\n");
    }
}
#endif