// @ignore tfmeta: eyJzaW5nbGVfdGVzdF9jYXNlIjogdHJ1ZSwgImZtdF9pbXBvcnRzIjogWyJkaXNwbGF5LmgiLCAiZXh0cmEudGVzdC5hc3NlcnQuaCIsICJleHRyYS5hcnJheS5oIl0sICJpb19maWxlcyI6IGZhbHNlfQ==
// author: [Laksh Kumar Sisodiya](https://github.com/thefcraft)
// please run `git clone https://github.com/thefcraft/fmt-display-cpp.git`
// and then copy pase `test.assert.h` file and `fmt` dir to the current folder
// and rename .cp.base_template.cpp to main.cpp and modify it to make your own template and enjoy :-)
// pase input text in `.in.txt`
// get output inside `.out.txt`


#include <iostream>
#include <vector>
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

const ull modulo = ull(1e9) + 7;

ll solver_helper(ull x, const ull n, const std::vector<ull> c){
    // Bottom-Up
    ull min_c = c[0];
    for (const ull &ci: c) if(ci<min_c) min_c = ci;
    
    std::vector<ull> answers = std::vector<ull>(x, 0);
    if (min_c <= x) answers[min_c - 1] = 1; // distinct integers ci //base case
    for (ull i = min_c; i<x; i++){
        for (const ull &ci: c){
            if(i+1 == ci) answers[i] ++;
            else if(i >= ci) answers[i] += answers[i-ci];
        }
        answers[i] %= modulo;
    }
    debug(answers);
    return answers[x-1];
}

// TODO: JUST CODE HERE
void solver(){
    // ll input(n, x); 
    ull input(n, x); 
    std::vector<ull> c = std::vector<ull>(n);
    for (int i = 0; i < n; i++) cin>>c[i];

    // std::vector<ll> memo = std::vector<ll>(x+1, -1);
    // cout<<solver_helper(x, n, c, memo)<<nl;

    cout<<solver_helper(x, n, c)<<nl;
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
        tin.set("3 9");
        tin.set("2 3 5");
        solver();
        asserttout("8\n");
    }
    It(failed){
        tin.set("1 1");
        tin.set("1000000");
        solver();
        asserttout("0\n");
    }
    It(failed real){
        tin.set("100 1000");
        tin.set("389 101 552 795 876 269 887 103 154 689 542 920 128 541 44 657 310 531 656 567 386 536 900 374 929 505 255 376 384 709 311 404 699 86 512 518 321 916 408 935 568 662 731 933 238 331 833 235 423 352 205 669 413 152 695 713 878 614 109 164 387 3 287 823 485 716 556 323 924 57 35 705 643 77 200 944 768 490 589 339 701 190 714 349 252 303 74 526 186 644 453 251 429 170 777 216 22 825 514 379");
        solver();
        asserttout("834994040\n");
    }
}
#endif