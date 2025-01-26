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
    template<typename T>
    void swap(T &a, T &b){
        T temp = a;
        a = b;
        b = temp;
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
    ll input(a, b);
    if(a == b){
        cout<<((a % 3 == 0)?YES:NO)<<nl;
        return;
    }
    // if(b > a){
    //     utils::swap(a, b);
    // }
    ll u = (2*a - b);
    ll v = (2*b - a);
    cout<<((u>=0 && v>=0 && u%3 == 0 && v%3 == 0)?YES:NO)<<nl;
    
    // (a > b)
    // b = b - a / 2;
    // if(b<0){
    //     cout<<NO<<nl;
    //     return;
    // }
    // NOTE: IT IS FUCKING TWO EQUATION TWO UNKNOWN [math is lang of universe aka universal approximation theorem]
    // DON'T THINK TOO DEEP IN WRONG DIRECTION
    // a = a % 2; // NOTE: THIS IS WRONG STEP YOU JUST ASSUME ALL WITHOUT ANY PROOF
    // if (a == 0){
    //     cout<<((b == 0)?YES:NO)<<nl;
    // }else{
    //     cout<<((b == 2)?YES:NO)<<nl;
    // }
    
    // if (a == 2*b){
    //     cout<<YES<<nl;
    //     return;
    // }
    // if(a > 2*b){
    //     cout<<NO<<nl;
    //     return;
    // }
    
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

    unsigned int t;
    cin >> t;
    while (t--) solver();
    return 0;
}

// sort(a, a+n, greater<int>());
// sort(a, a+n);

#ifdef DEBUG
MAKE_TESTS{
    // you can use this if you want...
    It(){
        tin.set("2 1");
        solver();
        asserttout("YES\n");
    }
    It(){
        tin.set("2 2");
        solver();
        asserttout("NO\n");
    }
    It(){
        tin.set("3 3");
        solver();
        asserttout("YES\n");
    }
    It(){
        tin.set("8 4");
        solver();
        asserttout("YES\n");
    }
    It(){
        tin.set("9 6");
        solver();
        asserttout("YES\n");
    }
    It(){
        tin.set("5 3");
        solver();
        asserttout("NO\n");
    }
    It(){
        tin.set("5 4");
        solver();
        asserttout("YES\n");
    }
    It(){
        tin.set("4 5");
        solver();
        asserttout("YES\n");
    }
    It(){
        tin.set("10 3");
        solver();
        asserttout("NO\n");
    }
    It(){
        tin.set("842572599 577431753");
        solver();
        asserttout("YES\n");
    }
    It(){
        tin.set("11 4");
        solver();
        asserttout("NO\n");
    }
    It(){
        tin.set("0 3");
        solver();
        asserttout("NO\n");
    }
}
#endif