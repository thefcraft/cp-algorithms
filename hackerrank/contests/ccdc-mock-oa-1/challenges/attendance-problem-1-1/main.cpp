// @ignore tfmeta: eyJzaW5nbGVfdGVzdF9jYXNlIjogZmFsc2UsICJmbXRfaW1wb3J0cyI6IFsiZGlzcGxheS5oIiwgImV4dHJhLnRlc3QuYXNzZXJ0LmgiLCAiZXh0cmEuYXJyYXkuaCJdLCAiaW9fZmlsZXMiOiBmYWxzZX0=
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

// TODO: JUST CODE HERE
void solver(){
    ull input(n); 
    ull inputn(arr, n);
    debug(fmt::sprint_array(arr, n));
    
    ull max_item = arr[0];
    for (ull i = 0; i < n; i++) if (arr[i] > max_item) max_item = arr[i];
    debug(max_item);
    ull max_num_bits = 0;
    while (max_item){
        max_item/=2;
        max_num_bits++;
    }
    debug(max_num_bits);
    
    ull max_common_bit = 0;
    ull pos = 1;
    for (ull idx = 0; idx < max_num_bits; idx++){
        debug(pos);
        ull count = 0;
        for (ull i = 0; i < n; i++) count += ((arr[i]&pos) > 0);
        debug(count);
        if (count > max_common_bit) max_common_bit = count;
        pos<<=1;
    }
    cout<<max_common_bit<<nl;
    
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
        tin.set("5", "9 3 30 4 1");
        solver();
        asserttout("3\n");
    }
    It(sample test case){
        tin.set("6", "22 14 18 16 9 17");
        solver();
        asserttout("4\n");
    }
    It(sample test case){
        tin.set("1", "3");
        solver();
        asserttout("1\n");
    }
}
#endif