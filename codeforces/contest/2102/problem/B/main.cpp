// @ignore tfmeta: eyJzaW5nbGVfdGVzdF9jYXNlIjogZmFsc2UsICJmbXRfaW1wb3J0cyI6IFsiZGlzcGxheS5oIiwgImJvb2wuaCIsICJleHRyYS5hcnJheS5oIiwgImV4dHJhLnRlc3QuYXNzZXJ0LmgiLCAibWFwLmgiLCAib3B0aW9uYWwuaCIsICJwYWlyLmgiLCAic2V0LmgiLCAidHVwbGUuaCIsICJ2YXJpYW50LmgiLCAidmVjdG9yLmgiXSwgImlvX2ZpbGVzIjogZmFsc2V9
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
        // #include XSTR(FMTDISPLAYPATH_BASE/display.h)
        // #include XSTR(FMTDISPLAYPATH_BASE/extra.test.assert.h)
        #include XSTR(FMTDISPLAYPATH_BASE/display.h)
		#include XSTR(FMTDISPLAYPATH_BASE/bool.h)
		#include XSTR(FMTDISPLAYPATH_BASE/extra.array.h)
		#include XSTR(FMTDISPLAYPATH_BASE/extra.test.assert.h)
		#include XSTR(FMTDISPLAYPATH_BASE/map.h)
		#include XSTR(FMTDISPLAYPATH_BASE/optional.h)
		#include XSTR(FMTDISPLAYPATH_BASE/pair.h)
		#include XSTR(FMTDISPLAYPATH_BASE/set.h)
		#include XSTR(FMTDISPLAYPATH_BASE/tuple.h)
		#include XSTR(FMTDISPLAYPATH_BASE/variant.h)
		#include XSTR(FMTDISPLAYPATH_BASE/vector.h)
    #else
        // #include "fmt/display.h" // https://github.com/thefcraft/fmt-display-cpp/tree/main/fmt
        // #include "fmt/extra.test.assert.h" // https://github.com/thefcraft/fmt-display-cpp/blob/main/test.assert.h
        #include "fmt/display.h"
		#include "fmt/bool.h"
		#include "fmt/extra.array.h"
		#include "fmt/extra.test.assert.h"
		#include "fmt/map.h"
		#include "fmt/optional.h"
		#include "fmt/pair.h"
		#include "fmt/set.h"
		#include "fmt/tuple.h"
		#include "fmt/variant.h"
		#include "fmt/vector.h"
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
    int input(n); // distinct...
    int input(target);
    if (target < 0) target = -target;
    int big = 0;
    for (int i = 1; i < n; i++){
        int input(ai);
        if (ai < 0) ai = -ai;
        if (ai>=target) big++;
    }
    if (n % 2 != 0){
        cout<<((big >= n/2)?YES:NO)<<nl;
    }else{
        cout<<(((big+1) >= n/2)?YES:NO)<<nl;
    }
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
    unsigned int input(t); while (t--) solver();
    return 0;
}

// sort(a, a+n, greater<int>());
// sort(a, a+n);

#ifdef DEBUG
MAKE_TESTS{
    // you can use this if you want...
    It(sample test case){
        tin.set("3", "2 3 1");
        solver();
        asserttout("YES\n");
    }
    It(sample test case){
        tin.set("5", "1 2 3 4 5");
        solver();
        asserttout("YES\n");
    }
    It(sample test case){
        tin.set("4", "4 2 0 -5");
        solver();
        asserttout("YES\n");
    }
    It(sample test case){
        tin.set("4", "-5 0 4 3");
        solver();
        asserttout("NO\n");
    }
    It(sample test case){
        tin.set("4", "-10 8 3 2");
        solver();
        asserttout("NO\n");
    }
    It(sample test case){
        tin.set("1", "1");
        solver();
        asserttout("YES\n");
    }
    It(sample test case){
        tin.set("10", "9 1000 -999 -13 456 -223 23 24 10 0");
        solver();
        asserttout("YES\n");
    }
}
#endif