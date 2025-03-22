// @ignore tfmeta: eyJzaW5nbGVfdGVzdF9jYXNlIjogdHJ1ZSwgImZtdF9pbXBvcnRzIjogWyJkaXNwbGF5LmgiLCAiZXh0cmEudGVzdC5hc3NlcnQuaCIsICJleHRyYS5hcnJheS5oIl0sICJpb19maWxlcyI6IGZhbHNlfQ==
// author: [Laksh Kumar Sisodiya](https://github.com/thefcraft)
// please run `git clone https://github.com/thefcraft/fmt-display-cpp.git`
// and then copy pase `test.assert.h` file and `fmt` dir to the current folder
// and rename .cp.base_template.cpp to main.cpp and modify it to make your own template and enjoy :-)
// pase input text in `.in.txt`
// get output inside `.out.txt`


#include <iostream>
#include <vector>
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

// ull solver_helper(ull n, std::vector<ull> &memo){
//     if (memo[n] != 0) return memo[n];
//     const ull modulo = 1e9+7;
//     ull ans = (
//         solver_helper(n-1, memo) + 
//         solver_helper(n-2, memo) + 
//         solver_helper(n-3, memo) + 
//         solver_helper(n-4, memo) + 
//         solver_helper(n-5, memo) + 
//         solver_helper(n-6, memo)
//     ) % modulo; // NOTE: i don't know why it was independent of % modulo in the sum??? 
//     // NOTE: hey it is (a + b) % n == (a%n + b%n) == (a%n + b%n) % n
//     memo[n] = ans;
//     return ans;
// }

// ull solver_helper(ull n){
//     // Bottom-Up
//     ull value = 1;
//     if (n < 6){
//         for (int i = 1; i < n; i++) value*=2;
//         return value;
//     }
//     ull last_ans[6];
//     for (int i = 0; i < 6; i++){
//         last_ans[i] = value;
//         value*=2;
//     }
//     debug(fmt::sprint_array(last_ans, 6));
//     const ull modulo = 1e9+7;
//     for (int i = 6; i < n; i++){
//         ull ans = (
//             last_ans[0] +
//             last_ans[1] +
//             last_ans[2] +
//             last_ans[3] +
//             last_ans[4] +
//             last_ans[5]
//         ) % modulo;
//         last_ans[0] = last_ans[1];
//         last_ans[1] = last_ans[2];
//         last_ans[2] = last_ans[3];
//         last_ans[3] = last_ans[4];
//         last_ans[4] = last_ans[5];
//         last_ans[5] = ans;
//     }
//     return last_ans[5];
// }

const ull modulo = 1e9+7;
ull solver_helper(ull n){
    // Bottom-Up
    if (n < 6) return 1ULL << (n-1);
    ull last_ans[6] = {1, 2, 4, 8, 16, 32};
    ull last_sum = 63; // 1 + 2 + 4 + 8 + 16 + 32
    for (int i = 6; i < n; i++){
        ull ans = last_sum % modulo;
        last_sum = (last_sum + ans - last_ans[i%6] + modulo) % modulo; 
        // NOTE: in above plus modulo because it may be last time flush out due to the % operation and become smaller
        // NOTE: in above last_ans[(i-6)%6] = last_ans[i%6]
        last_ans[i%6] = ans;
    }
    return last_ans[(n-1)%6];
}


// TODO: JUST CODE HERE
void solver(){
    ull input(n);
    // std::vector<ull> memo = std::vector<ull>(n+1, 0);
    // ull value = 1;
    // for (int i = 1; i <= (n>=6?6:n); i++){
    //     memo[i] = value;
    //     value*=2;
    // }
    // cout<<solver_helper(n, memo)<<nl;
    cout<<solver_helper(n)<<nl;
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
        tin.set("3");
        solver();
        asserttout("4\n");
    }    
    It(sample test case){
        tin.set("4");
        solver();
        asserttout("8\n");
    }
    It(sample test case){
        tin.set("5");
        solver();
        asserttout("16\n");
    }
    It(sample test case){
        tin.set("6");
        solver();
        asserttout("32\n");
    }
    It(sample test case){
        tin.set("7");
        solver();
        asserttout("63\n");
    }
    It(large){
        tin.set("1000");
        solver();
        asserttout("937196411\n");
    }
}
#endif