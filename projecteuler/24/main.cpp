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
inline int min(int a, int b){return a<b?a:b;}
inline int max(int a, int b){return a>b?a:b;}
ull factorial(ull a){
    if (a <= 1) return 1;
    return a*factorial(a-1);
}
int getIdxFromBuffer(bool buffer[], int n, int query) {
    int vidx = 0;
    int tidx = 0;
    while (vidx <= query){
        if (buffer[tidx]) tidx++;
        else{
            vidx++;
            tidx++;
        }
    }tidx--;
    return tidx;
}
ull find(ull query, const int d = 3){
    if (query < 1) return -1;
    
    // const int d = 3; // 0 1 2 3
    int answer[d] = {0};
    for (int i = 0; i < d; i++){
        const ull permute = factorial(d-i);
        while (query > permute) {
            query -= permute;
            answer[i]++;
        }
    }
    // for (int i = 0; i < d; i++) cout<<answer[i]<<" ";
    // cout<<" |  ";
    
    // generate number from answer
    // int result[d] = {-1};
    bool buffer[d+1] = {false};
    for (int i = 0; i < d; i++){
        int pos = getIdxFromBuffer(buffer, d, answer[i]);
        // result[i]
        cout<<pos;
        buffer[pos] = true;
    }
    int pos = getIdxFromBuffer(buffer, d, 0);
    cout<<pos;
    cout<<nl;
    return 0;
}
// TODO: JUST CODE HERE
void solver(){
    find(1000000, 9);
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
        asserttout("2783915460\n");
    }
    
    // It(internal){
    //     bool buffer[4] = {true, true, false, false};
    //     assert(getIdxFromBuffer(buffer, 4, 1) == 3);
    //     (getIdxFromBuffer(buffer, 4, 0) == 2);
    // }
    // It(internal){
    //     bool buffer[7] = {false, false, true, false, true, false, false};
    //     assert(getIdxFromBuffer(buffer, 7, 0) == 0);
    //     assert(getIdxFromBuffer(buffer, 7, 1) == 1);
    //     assert(getIdxFromBuffer(buffer, 7, 2) == 3);
    //     assert(getIdxFromBuffer(buffer, 7, 3) == 5);
    //     assert(getIdxFromBuffer(buffer, 7, 4) == 6);
    // }
}
#endif