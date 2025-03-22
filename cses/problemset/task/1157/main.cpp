// @ignore tfmeta: eyJzaW5nbGVfdGVzdF9jYXNlIjogdHJ1ZSwgImZtdF9pbXBvcnRzIjogWyJkaXNwbGF5LmgiLCAiZXh0cmEudGVzdC5hc3NlcnQuaCIsICJleHRyYS5hcnJheS5oIl0sICJpb19maWxlcyI6IGZhbHNlfQ==
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

ull square_number_smaller_then_or_equal(ull n){
    // if (n==0 || n==1 || n==2 || n == 3) return 1;
    ull j = 1;
    while(n>1){
        n>>=1;
        j<<=1;
    }
    return j;
}

ull solver_helper(ull m, ull n, ull moffset = 0){ // NOTE: all this for just m xor n
    // m, n are is one indexed each
    ull x = square_number_smaller_then_or_equal(m);
    ull y = square_number_smaller_then_or_equal(n);
    if (y == 1){
        debug(m);
        debug(n);
        debug(x);
        debug(y);
        debug(moffset);
        ull ans = moffset + m;
        if (n == 0) return ans; 
        return ans%2==0?ans + 1:ans-1;
    }
    if (x == y){
        return solver_helper(m-x, n-y+moffset); // fine 
    }
    if (y>x){
        return solver_helper(m, n-y, y+moffset); // TODO: offset is there
    }
    // y<x
    return solver_helper(m-x, n, x+moffset); // TODO: offset is there
}

// TODO: JUST CODE HERE
void solver(){
    ull input(m, n); 
    cout<<solver_helper(m-1, n-1)<<nl;
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
    It(btw it is just a fancy xor which i am unable to understand why){ // NOTE:
        asserteq(12^13, solver_helper(12, 13));
        asserteq(2^13, solver_helper(2, 13));
        asserteq(12^3, solver_helper(12, 3));
        asserteq(12^183, solver_helper(12, 183));
        asserteq(142^13, solver_helper(142, 13));
        asserteq(120^19, solver_helper(120, 19));
        asserteq(19^19, solver_helper(19, 19));
    }
    // you can use this if you want...
    It(sample test case){
        tin.set("3 5");
        solver();
        asserttout("6\n");
    }
    It(sample test case){
        tin.set("1 1");
        solver();
        asserttout("0\n");
    }
    It(sample test case){
        tin.set("1 2");
        solver();
        asserttout("1\n");
    }
    It(sample test case){
        tin.set("1 3");
        solver();
        asserttout("2\n");
    }
    It(sample test case){
        tin.set("2 3");
        solver();
        asserttout("3\n");
    }
    It(larger test case){
        tin.set("943339403 887839953");
        solver();
        asserttout("215051098\n");
    }
    It(larger test case){
        tin.set("58792638 990685865");
        solver();
        asserttout("948809749\n");
    }
    It(larger test case){
        tin.set("174443760 221357853");
        solver();
        asserttout("122973171\n");
    }
}
#endif