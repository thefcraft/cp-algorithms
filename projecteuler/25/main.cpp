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


#define toInt(c) ((int)c - 48)
#define toChar(i) ((char)(i + 48))
#define MAX(a, b) ((a)>(b)?(a):(b))


std::string add(std::string a, std::string b){
    ull len = MAX(a.length(), b.length());
    while (a.length() < len) a = "0" + a;
    while (b.length() < len) b = "0" + b;
    ull carry = 0;  
    ull* digits = new ull[len];
    
    for (ll i = len-1; i >=0; i--){
        ull summed = carry + toInt(a[i]) + toInt(b[i]);
        ull digit = summed % 10;
        digits[i] = digit;
        carry = summed/10;
    }
    std::string result = "";
    bool isLeadingZero = true;
    while (carry){
        char c = toChar(carry % 10);
        if (isLeadingZero && c != '0') isLeadingZero = false;
        if (!isLeadingZero) result += c;
        carry /= 10;
    }
    for (ll i = 0; i < len; i++) {
        char c = toChar(digits[i]);
        if (isLeadingZero && c != '0') isLeadingZero = false;
        if (!isLeadingZero) result += c;
    }
    if(isLeadingZero) result += '0';
    delete[] digits;
    return result;
}


// TODO: JUST CODE HERE
void solver(){
    std::string last = "1";
    std::string last_last = "1";
    ll idx = 2;
    while (last.length() < 1000){
        idx++;
        std::string tn = add(last, last_last);
        last_last = last;
        last = tn;
    }
    cout<<idx<<nl;
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
        asserttout("4782\n");
    }
    It(){
        {
            std::string a = "5";
            std::string b = "7";
            std::string c = "12";
            ll arr[5] = {1,2,3,4,5};
            asserteq(add(a, b), c);
        }
        {
            std::string a = "0";
            std::string b = "00";
            std::string c = "0";
            asserteq(add(a, b), c);
        }
        {
            std::string a = "1000";
            std::string b = "01200";
            std::string c = "2200";
            asserteq(add(a, b), c);
        }
        {
            std::string last = "1";
            std::string last_last = "1";
            ll idx = 2;
            while (last.length() < 3){
                idx++;
                std::string tn = add(last, last_last);
                last_last = last;
                last = tn;
            }
            asserteq(idx, 12);
        }
    }
}
#endif