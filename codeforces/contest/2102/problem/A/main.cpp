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
    int input(n, m, p, q); 
    
    // e.g. "n, m, p, q"
    // [a1, a2, a3, a4, ..., an]
    // [a1, ..., ap, ap_1, ..., an]
    // a1+a2+...+ap = q
    // a2+...+ap+ap_1 = q
    // a1+q = q+ap_1 => [NOTE: a1 = ap_1]
    // a2+...+ap+ap_1 = q
    // a3+...+ap+ap_1+ap_2 = q
    // a2+q = q+ap_2 => [NOTE: a2 = ap_2]

    // NOTE: => ai == ap_i == a2p_i

    // [a1, ..., ap, ap_1, ..., an]

    if (n%p == 0){
        // NOBUG: pass
        cout<<(m==(q*(n/p))?YES:NO)<<nl;
    }else{
        // NOBUG: todo
        // [a1, ..., ap, b1, ..., bp, c1, ..., cp, ..., ..., ..., y1, ..yk.., yp, z1, ..., zk]
        m = m-q*(n/p);
        n = n%p;
        debug(m);
        debug(n);
        // cout<<((m>0)?YES:NO)<<nl;
        cout<<YES<<nl;
        // failed on 5, 4, 2, 3
        // [a1, a2, b1, b2, c1] => 4
        // [3, 3, -2]
        // 
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
    // if ok suppose n%q == 0
    // ...
    // else 
    // [a1, ..., an] => m
    // [a1, ..., ap] => q + [ap+1, ..., an] => m-q

    // NOTE: they all are integer

    It(sample test case){
        // [a1, a2, a3] => 2
        // [a1, a2] => 1, [a3] => 2-1 => 1
        tin.set("3 2 2 1");
        solver();
        asserttout("YES\n");
    }
    It(sample test case){
        tin.set("1 1 1 1");
        solver();
        asserttout("YES\n");
    }
    It(sample test case){
        tin.set("5 4 2 3");
        // a1, ..., a5 
        // sum(...) = 4
        // sum_over_2(...) = 3
        solver();
        asserttout("YES\n");
    }
    It(sample test case){
        tin.set("10 7 5 2");
        // a1, ..., a10 
        // sum(...) = 7
        // sum_over_5(...) = 2
        solver();
        asserttout("NO\n");
    }
    It(sample test case){
        tin.set("4 4 1 3");
        solver();
        asserttout("NO\n");
    }
}
#endif