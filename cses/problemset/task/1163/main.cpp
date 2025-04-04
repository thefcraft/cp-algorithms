// @ignore tfmeta: eyJzaW5nbGVfdGVzdF9jYXNlIjogdHJ1ZSwgImZtdF9pbXBvcnRzIjogWyJkaXNwbGF5LmgiLCAiZXh0cmEudGVzdC5hc3NlcnQuaCIsICJleHRyYS5hcnJheS5oIiwgInBhaXIuaCJdLCAiaW9fZmlsZXMiOiBmYWxzZX0=
// author: [Laksh Kumar Sisodiya](https://github.com/thefcraft)
// please run `git clone https://github.com/thefcraft/fmt-display-cpp.git`
// and then copy pase `test.assert.h` file and `fmt` dir to the current folder
// and rename .cp.base_template.cpp to main.cpp and modify it to make your own template and enjoy :-)
// pase input text in `.in.txt`
// get output inside `.out.txt`


#include <iostream>
#include <map>
#include <set>
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
    int input(x, n); 
    map<int, pair<int, int>> gap = {{0, {-1, x}}, {x, {x, -1}}};
    set<pair<int, int>> lgap_sort = {{x, x}}; // not map because map can't store duplicates as its key is value of above one.
    // set<pair<int, int>> rgap_sort = {{x, 0}}; // not map because map can't store duplicates as its key is value of above one.
    // no need for rgap_sort as its keys are same as lgap_sort
    for (int i = 0; i < n; i++){
        int input(pi); // it is unique
        auto it_greater = gap.upper_bound(pi);
        // NOTE: i can't use x.lower_bound()-- but i can use --x.lower_bound() insted it_lower-- afterwards only if it is sure that it is not equal to begin...
        auto it_lower = --gap.lower_bound(pi); // it_lower--; 
        int lgap = pi - it_lower->first;
        int rgap = it_greater->first - pi;
        
        lgap_sort.erase({(it_greater->second).first, it_greater->first});
        // rgap_sort.erase({(it_lower->second).second, it_lower->first});
        
        (it_lower->second).second = lgap;
        (it_greater->second).first = rgap;
        // gap.insert({pi, {lgap, rgap}});
        
        lgap_sort.insert({rgap, it_greater->first});
        lgap_sort.insert({lgap, pi});

        // rgap_sort.insert({lgap, it_lower->first});
        // rgap_sort.insert({rgap, pi});

        // debug(gap);
        debug(lgap_sort);
        // debug(rgap_sort);
        // cout<<utils::max((*(--lgap_sort.end())).first, (*(--rgap_sort.end())).first)<<' ';
        cout<<(*(--lgap_sort.end())).first<<' ';
    }
    cout<<nl;
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
        tin.set("8 3", "3 6 2");
        solver();
        asserttout("5 3 3 \n");
    }
}
#endif