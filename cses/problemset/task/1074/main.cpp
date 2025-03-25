// @ignore tfmeta: eyJzaW5nbGVfdGVzdF9jYXNlIjogdHJ1ZSwgImZtdF9pbXBvcnRzIjogWyJkaXNwbGF5LmgiLCAiZXh0cmEudGVzdC5hc3NlcnQuaCIsICJleHRyYS5hcnJheS5oIl0sICJpb19maWxlcyI6IGZhbHNlfQ==
// author: [Laksh Kumar Sisodiya](https://github.com/thefcraft)
// please run `git clone https://github.com/thefcraft/fmt-display-cpp.git`
// and then copy pase `test.assert.h` file and `fmt` dir to the current folder
// and rename .cp.base_template.cpp to main.cpp and modify it to make your own template and enjoy :-)
// pase input text in `.in.txt`
// get output inside `.out.txt`


#include <iostream>
#include <algorithm>
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
        // #include XSTR(FMTDISPLAYPATH_BASE/display.h)
        // #include XSTR(FMTDISPLAYPATH_BASE/extra.test.assert.h)
        #include XSTR(FMTDISPLAYPATH_BASE/display.h)
		#include XSTR(FMTDISPLAYPATH_BASE/extra.test.assert.h)
		#include XSTR(FMTDISPLAYPATH_BASE/extra.array.h)
    #else
        // #include "fmt/display.h" // https://github.com/thefcraft/fmt-display-cpp/tree/main/fmt
        // #include "fmt/extra.test.assert.h" // https://github.com/thefcraft/fmt-display-cpp/blob/main/test.assert.h
        #include "fmt/display.h"
		#include "fmt/extra.test.assert.h"
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
    
    // Swaps two values
    template <typename T>
    void swap(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }
    // Returns the minimum of two values
    template <typename T>
    inline T min(T a, T b) {
        return (a < b) ? a : b;
    }
    // Returns the maximum of two values
    template <typename T>
    inline T max(T a, T b) {
        return (a > b) ? a : b;
    }
    // Returns the absolute value of a number
    template <typename T>
    inline T abs(T a) {
        return (a < 0) ? -a : a;
    }
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
    ll inputn(P, n);
    // ll avg = P[0]; // NOTE: we take avg in case of min((x - P[i])**2) but here it is min(|x - P[i]|) (from math formula, dc/dx where c is cost);
    // and in this case we want that half values are +ve and half are -ve, |x-P[i]| and that x is answer
    sort(P, P+n);
    int m = n / 2;
    ull cost = 0;
    for (int i = 0; i < n; i++) cost += utils::abs(P[m] - P[i]);
    debug(P[m]);
    cout<<cost<<nl;
}

int main(){
    #ifdef DEBUG
        fmt::println(ansi::red, "Debugging information: Program running in debug mode.", ansi::reset);
        RUN_TESTS;
        // freopen(".in.txt", "r", stdin); // read from .in.txt
        // freopen(".out.txt", "w", stdout); // write to .out.txt
        return 0;
    #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // unsigned int t;
    // cin >> t;
    // while (t--) solver();
    solver();
    return 0;
}

// sort(a, a+n, greater<int>());
// sort(a, a+n);

#ifdef DEBUG
MAKE_TESTS{
    // you can use this if you want...
    It(sample test case){
        tin.set("5", "2 3 1 5 2");
        solver();
        asserttout("5\n");
    }
    It(edge case){
        tin.set("1", "2");
        solver();
        asserttout("0\n");
    }
    It(edge case){
        tin.set("2", "2 2");
        solver();
        asserttout("0\n");
    }
    It(edge case){
        tin.set("2", "2 1");
        solver();
        asserttout("1\n");
    }
    It(edge case){
        tin.set("3", "2 1 2");
        solver();
        asserttout("1\n");
    }
    It(failed){
        tin.set("5", "1 4 5 100 100");
        solver();
        asserttout("195\n");
    }
    It(){
        tin.set("5", "1 3 5 10 10");
        solver();
        asserttout("16\n");
    }
    It(){
        tin.set("4", "1 2 5 10");
        solver();
        asserttout("12\n");
    }
}
#endif