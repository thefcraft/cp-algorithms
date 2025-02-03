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


ull helper(ull p[], int idxoffset, int n, ull halfsum){
    if(n == idxoffset) return 0;
    ull yes_take = p[idxoffset] + helper(p, idxoffset + 1, n, halfsum - p[idxoffset]);
    if (yes_take > halfsum) yes_take = 0;
    ull not_take = helper(p, idxoffset + 1, n, halfsum);
    if (yes_take > not_take) return yes_take;
    return not_take;
}


// TODO: JUST CODE HERE
void solver(){
    int input(n); 
    ull inputn(p, n);
    ull fullsum = 0;
    for (size_t i = 0; i < n; i++) fullsum += p[i]; 
    ull halfsum=fullsum/2;
    debug(halfsum);
    ull max_sum_less_then_halfsum = helper(p, 0, n, halfsum);
    debug(max_sum_less_then_halfsum);
    
    cout<<fullsum - 2*max_sum_less_then_halfsum<<nl;
    
    // why greedy you know that it will fails... // we can use recursion as n is less then 20
    // ull suma = 0;
    // ull sumb = 0;
    // for (int i = 0; i < n; i++){
    //     if (suma < sumb) suma += p[i];
    //     else sumb += p[i];
    // }
    // cout<<(suma>sumb?suma - sumb:sumb - suma)<<nl;
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
    It(sample test){
        tin.set(
            "5",
            "3 2 7 4 1"
        );
        solver();
        asserttout("1\n");
    }
    It(sample test){
        tin.set(
            "1",
            "3"
        );
        solver();
        asserttout("0\n");
    }

}
#endif