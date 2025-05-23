// author: [Laksh Kumar Sisodiya](https://github.com/thefcraft)
// please run `git clone https://github.com/thefcraft/fmt-display-cpp.git`
// and then copy pase `test.assert.h` file and `fmt` dir to the current folder
// and rename .cp.base_template.cpp to main.cpp and modify it to make your own template and enjoy :-)
// pase input text in `.in.txt`
// get output inside `.out.txt`


#include <iostream>
#include <cstdint>
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

#ifdef DEBUG
template<>
struct fmt::Display<uint64_t> {
    static std::string print(const uint64_t &data) {
        fmt::fmtout out;
        out<<'\n';
        for (int i = 63; i >= 0; --i) {
            out << (int)((data >> i) & 1) << ' ';  // Print the bit at position i
            if (i % 8 == 0 && i != 0) out<<'\n';  // Add a newline after every 8 bits
        }
        return out.str();
    }
};
#endif
void updateAttackerMask_(uint64_t &attackerMask, int x, int y){ // index start by zero
    for (int i = 0; i < 8; i++){
        int idx = (8+8*i) - (x+1);
        attackerMask |= (1ULL << idx);
    }
    for (int i = 0; i < 8; i++){
        int idx = (8+8*y) - (i+1);
        attackerMask |= (1ULL << idx);
    }

    for (int i = 0; y+i <= 7 && x+i <= 7; i++){
        int idx = (8+8*(y+i)) - ((x+i)+1);
        attackerMask |= (1ULL << idx);
    }
    for (int i = 0; y-i >= 0 && x-i >= 0; i++){
        int idx = (8+8*(y-i)) - ((x-i)+1);
        attackerMask |= (1ULL << idx);
    }
    // ERROR
    // for (uint i = 0; y+i <= 7 && x-i >= 0; i++){
    //     uint idx = (8+8*(y+i)) - ((x-i)+1);
    //     attackerMask |= (1ULL << idx);
    // }
    // for (uint i = 0; y-i >= 0&& x+i <= 7; i++){
    //     uint idx = (8+8*(y-i)) - ((x+i)+1);
    //     attackerMask |= (1ULL << idx);
    // }
    for (int i = 0; y+i <= 7 && x-i >= 0; i++){
        int idx = (8+8*(y+i)) - ((x-i)+1);
        attackerMask |= (1ULL << idx);
    }
    for (int i = 0; y-i >= 0 && x+i <= 7; i++){
        int idx = (8+8*(y-i)) - ((x+i)+1);
        attackerMask |= (1ULL << idx);
    }
}
uint64_t updateAttackerMask(uint64_t attackerMask, int x, int y){ // index start by zero
    updateAttackerMask_(attackerMask, x, y);
    return attackerMask;
}
void helper(uint64_t attackerMask, uint64_t reserved, uint &ans, int row=0, uint64_t queens = 0){
    if (row == 8){
        ans++;
        return;
    }
    for (int i = 0; i < 8; i++){
        int idx = (8+8*i) - (row+1);
        if ((reserved & (1ULL << idx)) != 0ULL) continue; 
        if ((attackerMask & (1ULL << idx)) != 0ULL) continue;
        uint64_t attackerMaskTmp = updateAttackerMask(attackerMask, row, i);
        helper(attackerMaskTmp, reserved, ans, row+1, queens | (1ULL << idx));
    }
}
// TODO: JUST CODE HERE
void solver(){
    uint64_t reserved = 0;
    for (int i = 0; i < 64; i++){
        int idx = 8*((63-i)/8) + 7-i%8;
        char input(tmp);
        if(tmp == '*') reserved |= (1ULL << idx);
    }
    debug(reserved);
    // uint64_t queens = 0;
    // queens |= (1ULL << (8+8*(1)) - ((0)+1));
    // queens |= (1ULL << (8+8*(1)) - ((6)+1));
    // queens |= (1ULL << (8+8*(5)) - ((2)+1));
    // debug(queens);
    uint64_t attackerMask = 0;
    // updateAttackerMask_(attackerMask, 0, 1);
    // updateAttackerMask_(attackerMask, 6, 1);
    // updateAttackerMask_(attackerMask, 1, 5);
    // debug(attackerMask);
    uint ans = 0;
    helper(attackerMask, reserved, ans);
    cout<<ans<<nl;
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
            "........",
            "........",
            "..*.....",
            "........",
            "........",
            ".....**.",
            "...*....",
            "........"
        );
        solver();
        asserttout("65\n");
    }
}
#endif