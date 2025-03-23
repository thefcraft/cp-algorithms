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



#define toInt(x) ((int)x - 48)
#define toChar(x) ((char)(x + 48))

int numLen(int n, int base = 10){
    int result = 0;
    while (n){
        result ++;
        n/=base;
    }
    return result;
}
inline int max(int a, int b){return a>b?a:b;}
string add(string a, string b){
    int len = max(a.length(), b.length());
    while (a.length() < len) a = "0" + a;
    while (b.length() < len) b = "0" + b;
    int adder = 0;  
    int* digits = new int[len];
    for (int i = len-1; i >=0; i--){
        int summed = adder + toInt(a[i]) + toInt(b[i]);
        int digit = summed % 10;
        digits[i] = digit;
        adder = summed/10;
    }
    string result = "";
    while (adder){
        result += toChar(adder % 10);
        adder /= 10;
    }
    for (int i = 0; i < len; i++) result += toChar(digits[i]);
    delete[] digits;
    return result;
}
string mul(string value, int n){
    int* digits = new int[value.length()];
    int adder = 0;
    for (int i = value.length()-1; i >= 0; i--){
        int vi = toInt(value[i])*n+adder;
        int digit = vi % 10;
        digits[i] = digit;
        adder = vi/10;
    }
    string result = "";
    while (adder){
        result += toChar(adder % 10);
        adder /= 10;
    }
    for (int i = 0; i < value.length(); i++) result += toChar(digits[i]);
    delete[] digits;
    return result;
}
string mul(string a, string b){
    int depth = 0;
    string result = "0";
    for (int i = b.length()-1; i >= 0; i--){
        string x = mul(a, toInt(b[i]));
        for (int j = 0; j < depth; j++) x += "0";
        result = add(result, x);
        depth++;
    }
    
    return result;
}

// TODO: JUST CODE HERE
void solver(){
    string result = "100";
    for (int i = 99; i > 1; i--){
        string a = "";
        int x = i;
        while (x){
            a += toChar(x % 10);
            x /= 10;
        }
        string b = "";
        for (int i = a.length() - 1; i >=0; i--) b+=a[i];
        result = mul(result, b);
    }
    int x = 0;
    for (char c: result) x+= toInt(c);
    cout<<x<<nl;
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
        asserttout("648\n");
    }
}
#endif