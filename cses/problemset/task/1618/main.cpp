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
    ull input(n); 
    
    ull number_of_5_in_prime_factor_of_factorial_n = 0;
    // ull number_of_2_in_prime_factor_of_factorial_n = 0; // always greater as always factor of 2 is more then 5 in factorial; every 2nd is even

    for(ull i = 5; i<=n; i*=5) number_of_5_in_prime_factor_of_factorial_n += n/i;
    cout<<number_of_5_in_prime_factor_of_factorial_n<<nl; // always this case as factor of 2 is always greater

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
    It(){
        tin.set("20");
        solver();
        asserttout("4\n");
    }
    It(){
        tin.set("5");
        solver();
        asserttout("1\n");
    }
    It(){
        tin.set("11");
        solver();
        asserttout("2\n");
    }
    It(){
        tin.set("15");
        solver();
        asserttout("3\n");
    }
    It(){
        tin.set("100");
        solver();
        asserttout("24\n");
    }
    It(){
        tin.set("27");
        solver();
        asserttout("6\n");
    }
}
#endif