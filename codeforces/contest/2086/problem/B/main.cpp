// @ignore tfmeta: eyJzaW5nbGVfdGVzdF9jYXNlIjogZmFsc2UsICJmbXRfaW1wb3J0cyI6IFsiZGlzcGxheS5oIiwgImV4dHJhLnRlc3QuYXNzZXJ0LmgiLCAiZXh0cmEuYXJyYXkuaCIsICJwYWlyLmgiXSwgImlvX2ZpbGVzIjogZmFsc2V9
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
		#include XSTR(FMTDISPLAYPATH_BASE/pair.h)
    #else
        // #include "fmt/display.h" // https://github.com/thefcraft/fmt-display-cpp/tree/main/fmt
        // #include "fmt/extra.test.assert.h" // https://github.com/thefcraft/fmt-display-cpp/blob/main/test.assert.h
        #include "fmt/display.h"
		#include "fmt/extra.test.assert.h"
		#include "fmt/extra.array.h"
		#include "fmt/pair.h"
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
    
    // Swaps two values
    template <typename T>
    void swap(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }
    // Returns the minimum of two values
    template <typename T>
    inline T min(T a, T b) {
        return (a < b) ? a : b;
    }
    // Returns the maximum of two values
    template <typename T>
    inline T max(T a, T b) {
        return (a > b) ? a : b;
    }
    // Returns the absolute value of a number
    template <typename T>
    inline T abs(T a) {
        return (a < 0) ? -a : a;
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
    ull input(n, k, x); 
    ull inputn(arr, n);
    ull total_sum = 0;
    for (int i = 0; i < n; i++) total_sum += arr[i];
    ull total_total_sum = (total_sum * k);
    if ( total_total_sum < x) cout<<0<<nl;
    else if (total_total_sum == x) cout<<1<<nl;
    // else if (total_sum >= x){
    //     int i = n-1;
    //     ull current_sum = 0;
    //     while ((current_sum + arr[i]) < x) current_sum += arr[i--];
    //     // debug(i);
    //     // debug(n*(k-1) + i + 1);
    //     cout<<n*(k-1) + i + 1<<nl;
    // }
    else{//else if(total_sum < x){
        ull offset = x / total_sum; // NOTE: i forgot to check a case in which x % total_sum == 0
        ull offset_adder = x % total_sum == 0;
        x -= (total_sum * offset);
        k -= offset;
        // debug(k);
        // debug(x);
        // debug(offset);
        int i = n-1;
        ull current_sum = 0;
        while ((current_sum + arr[i]) < x) current_sum += arr[i--];
        // debug(i);
        // debug(n*(k-1) + i + 1);
        cout<<n*(k-1) + i + 1 + offset_adder<<nl;
    }
    // else{ // total_sum == x
    //     cout<<n*(k-1) + 1<<nl;
    // }
    
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
        tin.set("5 3 10", "3 4 2 1 5");
        solver();
        asserttout("12\n");
    }
    It(sample test case){
        tin.set("15 97623 1300111", "105 95 108 111 118 101 95 118 97 108 111 114 97 110 116");
        solver();
        asserttout("1452188\n");
    }
    It(sample test case){
        tin.set("1 100000 1234567891011", "1");
        solver();
        asserttout("0\n");
    }
    It(sample test case){
        tin.set("1 1 1", "1");
        solver();
        asserttout("1\n");
    }
    It(sample test case){
        tin.set("1 1 1", "2");
        solver();
        asserttout("1\n");
    }
    It(sample test case){
        tin.set("2 1 2", "1 1");
        solver();
        asserttout("1\n");
    }
    It(sample test case){
        tin.set("2 1 5", "2 1");
        solver();
        asserttout("0\n");
    }
    It(sample test case){
        tin.set("5 3 22", "3 4 2 1 5");
        solver();
        asserttout("8\n");
    }
    It(sample test case){
        tin.set("5 3 36", "3 4 2 1 5");
        solver();
        asserttout("4\n");
    }
    It(sample test case){
        tin.set("5 4 36", "3 4 2 1 5");
        solver();
        asserttout("9\n");
    }
    It(sample test case){
        tin.set("5 5 36", "3 4 2 1 5");
        solver();
        asserttout("14\n");
    }
    It(failed case){
        tin.set("5 3 30", "3 4 2 1 5");
        solver();
        asserttout("6\n");
    }
    It(failed case){
        tin.set("5 3 31", "3 4 2 1 5");
        solver();
        asserttout("5\n");
    }
}
#endif