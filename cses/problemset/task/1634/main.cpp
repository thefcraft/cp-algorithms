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

// ll solver_helper(ll x, ull &n, std::vector<ull> &c, std::vector<ll> &memo){
//     // debug(x);
//     if (memo[x] != -2) return memo[x];
//     if (x <= 0) return -1;
//     ll ans = -1;
//     for (ll i = 0; i < n; i++) {
//         if (x > c[i]){
//             const ll call_result = solver_helper(x-c[i], n, c, memo);
//             if (call_result != -1 && (1+call_result < ans || ans == -1)) ans = 1+call_result;
//         }
//         else if(x==c[i] && ans == -1) ans = 1;
//     }
//     memo[x] = ans;
//     return ans;
// }

// [-2, -1, 1, 1, 1, 2, 2, 2, 1, 1, 2, 1, 2, 2, 1, 2, 1, 1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 
//  2, 2, 2, 2, 2, 2, 3, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 3, 4, 4, 4, 4, 4, 
//  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 
//  5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 
//  7, 7, 7, 7, 7, 8, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 8, 9, 9, 9, 9, 9, 9, 
//  9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 
//  10, 10, 10, 11, 10, 11, 11, 11, 11, 11, 11, 11, 11, -2, 11]
ll solver_helper(ull x, ull n, std::vector<ull> c){
    // Bottom-Up
    std::vector<ll> answers = std::vector<ll>(x, -1);

    ull min_c = c[0];
    for (const ull &ci: c)
        if (ci < min_c) min_c = ci;
    if (min_c <= x) answers[min_c-1] = 1; // base case
    // TOOO: for more optim we can use i+=lcm etc etc and return -1 using lcm precomputed etc etc, 
    // TODO: also we can shrink the size of answers by a factor of lcm
    // TODO: if c has len 1 then also we can do something...
    for (int i = min_c; i < x; i++){
        ll ans = -1;
        for (const ull &ci: c){
            if(i+1 == ci) ans = 1;
            else if (i >= ci){ // ? or > both are same 
                const ll call_result = answers[i-ci];
                if (call_result != -1 && (
                    (1+call_result < ans) || (ans == -1)
                )) ans = 1+call_result;
            }
        }
        answers[i] = ans;
    }
    // debug(answers);
    return answers[x-1];
}

// TODO: JUST CODE HERE
void solver(){
    // ll input(n, x); 
    ull input(n, x); 
    std::vector<ull> c = std::vector<ull>(n);
    for (int i = 0; i < n; i++) cin>>c[i];
    // sort(c.begin(), c.end(), greater<int>()); // NOTE: I DON'T WHY SHORT WORKS ???
    // std::vector<ll> memo = std::vector<ll>(x+1, -2);
    // cout<<solver_helper(x, n, c, memo)<<nl;
    // debug(memo);
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
        tin.set("3 11");
        tin.set("1 5 7");
        solver();
        asserttout("3\n");
    }
    It(passed){
        tin.set("100 1000000");
        tin.set("1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100");
        solver();
        asserttout("10000\n");
    }
    It(TODO: hacked on this test even though it passes the cses due to stack overflow_error){ // TODO: use dp to optimise the recursion
        tin.set("1 1000000");
        tin.set("1");
        solver();
        asserttout("1000000\n");
    }
    It(){
        tin.set("1 100");
        tin.set("1");
        solver();
        asserttout("100\n");
    }
    It(){
        tin.set("1 1");
        tin.set("1000000");
        solver();
        asserttout("-1\n");
    }
    It(){
        tin.set("2 10");
        tin.set("3 6");
        solver();
        asserttout("-1\n");
    }
    It(){
        tin.set("10 200");
        tin.set("2 3 4 8 9 11 14 16 17 19");
        solver();
        asserttout("11\n");
    }
}
#endif