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


bool isLeapYear(int year){
    return (year % 100 == 0 && year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}
int totalDaysPassedSince1Jan1900(int year){
    int result = 0;
    for (int i = 1900; i < year; i++){
        if (isLeapYear(i)) result += 366;
        else result += 365;
    }
    return result;
}
int numSundaysFellFirstOfMonth(int year) {
    int totalDays = totalDaysPassedSince1Jan1900(year);
    int offset = totalDays%7;
    int result = 0;
    result += ((offset + 31)%7==6);
    result += ((offset + 31 + 28 + isLeapYear(year))%7==6);
    result += ((offset + 31*2 + 28 + isLeapYear(year))%7==6);
    result += ((offset + 31*2 + 30 + 28 + isLeapYear(year))%7==6);
    result += ((offset + 31*3 + 30 + 28 + isLeapYear(year))%7==6);
    result += ((offset + 31*3 + 30*2 + 28 + isLeapYear(year))%7==6);
    result += ((offset + 31*4 + 30*2 + 28 + isLeapYear(year))%7==6);
    result += ((offset + 31*5 + 30*2 + 28 + isLeapYear(year))%7==6);
    result += ((offset + 31*5 + 30*3 + 28 + isLeapYear(year))%7==6);
    result += ((offset + 31*6 + 30*3 + 28 + isLeapYear(year))%7==6);
    result += ((offset + 31*6 + 30*4 + 28 + isLeapYear(year))%7==6);
    result += ((offset + 31*7 + 30*4 + 28 + isLeapYear(year))%7==6);
    return result;
}

// TODO: JUST CODE HERE
void solver(){
// Monday == 0 ... Sunday == 6.
    int result = 0;
    for (int i = 1901; i <= 2000; i++){
        result += numSundaysFellFirstOfMonth(i);
    }
    
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
        asserttout("171\n");
    }
    It(internal){
        // Divisible by 400
        assert(isLeapYear(1600) == true);
        assert(isLeapYear(2000) == true);
        
        // Divisible by 100 but not 400
        assert(isLeapYear(1700) == false);
        assert(isLeapYear(1800) == false);
        assert(isLeapYear(1900) == false);
        
        // Divisible by 4 but not 100
        assert(isLeapYear(1996) == true);
        assert(isLeapYear(2004) == true);
        
        // Not divisible by 4
        assert(isLeapYear(1901) == false);
        assert(isLeapYear(2001) == false);
        
        // Edge cases
        assert(isLeapYear(0) == true);  // The year 0 is considered a leap year in the Gregorian calendar.
        assert(isLeapYear(1) == false); // Year 1 is not a leap year.
    }
}
#endif