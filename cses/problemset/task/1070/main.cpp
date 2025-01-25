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

// TODO: JUST CODE HERE
void solver(){
    // int input(n, m, k); 
    // int inputn(arr, n);
    // just 
    // 1 _ 2 _ 3 _ 4
    // _ 5 _ 6 _ 7 _ 8
    // 1 5 2 6 3 7 4 8
    // 1 5 2 6 3 7 4
    // 1 6 2 7 3 8 4 9 5
    uint input(n);

    if (n == 2 || n == 3){ 
        cout<<"NO SOLUTION"<<nl;
        return;
    }

    for (uint i = 2; i <= n ; i+=2){
        cout<<i<<' ';
    }
    for (uint i = 1; i <= n ; i+=2){
        cout<<i<<' ';
    }

    // NOTE: Don't stuck to a single idea it may leads to local optimal solution not global one
    // if (n == 1){
    //     cout<<1<<nl;
    //     return;
    // }
    // if (n == 2 || n == 3){ //  || n == 4 exists
    //     cout<<"NO SOLUTION"<<nl;
    //     return;
    // }
    // if(n == 4){
    //     cout<<"2 4 1 3 "<<nl;
    //     return;
    // }

    // uint arr[n] = {0};
    // uint i = 0;
    // for (; 2*i < n; i++){
    //     arr[2*i] = i+1;
    // }
    // for (uint j = 1; j < n; j+=2){
    //     arr[j] = i+++1;
    // }
    // for (auto &ai: arr){
    //     cout<<ai<<' ';
    // }
    cout<<nl;
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
    It(YES){
        tin.set("5");
        solver();
        // asserttout("1 4 2 5 3 \n");
        asserttout("2 4 1 3 5 \n");
    }
    It(YES){
        tin.set("6");
        solver();
        // asserttout("1 4 2 5 3 6 \n");
        asserttout("2 4 6 1 3 5 \n");
    }
    It(YES){
        tin.set("4");
        solver();
        asserttout("2 4 1 3 \n"); // NOTE: first even cycle not odd here...
    }
    It(NO){
        tin.set("3");
        solver();
        asserttout("NO SOLUTION\n");
    }
}
#endif