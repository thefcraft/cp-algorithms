// @ignore tfmeta: eyJzaW5nbGVfdGVzdF9jYXNlIjogdHJ1ZSwgImZtdF9pbXBvcnRzIjogWyJkaXNwbGF5LmgiLCAiZXh0cmEudGVzdC5hc3NlcnQuaCIsICJleHRyYS5hcnJheS5oIl0sICJpb19maWxlcyI6IGZhbHNlfQ==
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

int numLen(int n, const int base = 10){
    int result = 0;
    while (n){
        result ++;
        n/=base;
    }
    return result;
}
string numToString(int num){
    // only for [1 to 1000]
    if (num == 1000) return "onethousand";
    
    const int first = num%10;
    const int second = (num / 10)%10;
    const int third = (num / 10)/10;

    string result = "";
    
    if (third == 1) result += "onehundred";
    else if (third == 2) result += "twohundred";
    else if (third == 3) result += "threehundred";
    else if (third == 4) result += "fourhundred";
    else if (third == 5) result += "fivehundred";
    else if (third == 6) result += "sixhundred";
    else if (third == 7) result += "sevenhundred";
    else if (third == 8) result += "eighthundred";
    else if (third == 9) result += "ninehundred";

    if (third != 0 && (second != 0 || first != 0)) result += "and";

    if (second == 1){
        if (first == 0) result += "ten";
        if (first == 1) result += "eleven";
        if (first == 2) result += "twelve";
        if (first == 3) result += "thirteen";
        if (first == 4) result += "fourteen";
        if (first == 5) result += "fifteen";
        if (first == 6) result += "sixteen";
        if (first == 7) result += "seventeen";
        if (first == 8) result += "eighteen";
        if (first == 9) result += "nineteen";
    }
    else if (second == 2) result += "twenty";
    else if (second == 3) result += "thirty";
    else if (second == 4) result += "forty";
    else if (second == 5) result += "fifty";
    else if (second == 6) result += "sixty";
    else if (second == 7) result += "seventy";
    else if (second == 8) result += "eighty";
    else if (second == 9) result += "ninety";
    
    if (second == 1);
    else if (first == 1) result += "one";
    else if (first == 2) result += "two";
    else if (first == 3) result += "three";
    else if (first == 4) result += "four";
    else if (first == 5) result += "five";
    else if (first == 6) result += "six";
    else if (first == 7) result += "seven";
    else if (first == 8) result += "eight";
    else if (first == 9) result += "nine";
    return result;
}

// TODO: JUST CODE HERE
void solver(){
    int result = 0;
    for (int i = 1; i <= 1000; i++) result += numToString(i).length();
    cout<<result<<nl;
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
        tin.set("");
        solver();
        asserttout("21124\n");
    }
}
#endif