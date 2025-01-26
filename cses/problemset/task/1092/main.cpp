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
    uint input(n);
    uint mod4 = n%4;
    if (!(mod4==3 || mod4==0)){
        cout<<NO<<nl;
        return;
    }
    cout<<YES<<nl;
    if(mod4 == 0){
        cout<<n/2<<nl;
        cout<<1<<' '<<4<<' ';
        for (uint i = 5; i <= n; i+=4){
            cout<<i<<' '<<i+3<<' ';
        }cout<<nl;

        cout<<n/2<<nl;
        cout<<2<<' '<<3<<' ';
        for (uint i = 5; i <= n; i+=4){
            cout<<i+1<<' '<<i+2<<' ';
        }cout<<nl;
        return;
    }
    cout<<(n+1)/2<<nl;
    cout<<1<<' '<<2<<' ';
    for (uint i = 4; i <= n; i+=4){
        cout<<i<<' '<<i+3<<' ';
    }cout<<nl;

    cout<<n/2<<nl;
    cout<<3<<' ';
    for (uint i = 4; i <= n; i+=4){
        cout<<i+1<<' '<<i+2<<' ';
    }cout<<nl;
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
    It(7){
        tin.set("7");
        solver();
        asserttout("YES\n4\n1 2 4 7 \n3\n3 5 6 \n");
    }
    It(11){
        tin.set("11");
        solver();
        asserttout("YES\n6\n1 2 4 7 8 11 \n5\n3 5 6 9 10 \n");
    }
    It(8){
        tin.set("6");
        solver();
        asserttout("NO\n");
    }
    It(3){
        tin.set("3");
        solver();
        asserttout("YES\n2\n1 2 \n1\n3 \n");
    }
    It(2){
        tin.set("2");
        solver();
        asserttout("NO\n");
    }
    It(1){
        tin.set("1");
        solver();
        asserttout("NO\n");
    }
    It(8){
        tin.set("8");
        solver();
        asserttout(
            "YES", 
            "4",
            "1 4 5 8 ",
            "4",
            "2 3 6 7 \n");
    }
    It(4){
        tin.set("4");
        solver();
        asserttout(
            "YES",
            "2",
            "1 4 ",
            "2",
            "2 3 \n");
    }
}
#endif