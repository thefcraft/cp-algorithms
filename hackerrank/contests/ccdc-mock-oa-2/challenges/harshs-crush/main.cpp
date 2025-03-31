// @ignore tfmeta: eyJzaW5nbGVfdGVzdF9jYXNlIjogZmFsc2UsICJmbXRfaW1wb3J0cyI6IFsiZGlzcGxheS5oIiwgImV4dHJhLnRlc3QuYXNzZXJ0LmgiLCAiZXh0cmEuYXJyYXkuaCIsICJwYWlyLmgiXSwgImlvX2ZpbGVzIjogZmFsc2V9
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
    int input(n); 
    if(n==1 || n == 3) cout<<-1;
    else if (n%2 == 0){
        for (int i = 1; i<=n; i+=2)
            cout<<i+1<<' '<<i<<' ';
    }else{
        for (int i = 1; i<=n-5; i+=2)
            cout<<i+1<<' '<<i<<' ';
        // cout<<n-3<<' '<<n<<' '<<n-4<<' '<<n-2<<' '<<n-1<<' '; // NOTE: i submited this line insted of the below one...
        cout<<n-3<<' '<<n-2<<' '<<n<<' '<<n-4<<' '<<n-1<<' ';
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
    unsigned int input(t); while (t--) solver();
    return 0;
}

// sort(a, a+n, greater<int>());
// sort(a, a+n);

#ifdef DEBUG
bool check_output(int n){
    tin.set(gettout);
    int flag = true;
    int xor_nums = 0;
    for (int i = 1; i <= n; i++){
        int ai; cin>>ai;
        xor_nums = utils::abs(ai - i) ^ xor_nums;
        flag = flag && (ai != i);
    }
    return flag && (xor_nums == 0);
}

MAKE_TESTS{
    // you can use this if you want...
    It(sample test case){
        tin.set("1");
        solver();
        asserttout("-1\n");
    }
    It(sample test case){
        tin.set("2");
        solver();
        asserttout("2 1 \n");
        assert(check_output(2));
    }
    
    It(sample test case){
        tin.set("4");
        solver();
        asserttout("2 1 4 3 \n");
        assert(check_output(4));
    }
    It(sample test case){
        tin.set("3");
        solver();
        asserttout("-1\n");
    }
    It(sample test case){
        tin.set("11");
        solver();
        asserttout("2 1 4 3 6 5 8 9 11 7 10 \n");
        assert(check_output(11));
    }
    It(sample test case){
        tin.set("13");
        solver();
        asserttout("2 1 4 3 6 5 8 7 10 11 13 9 12 \n");
        assert(check_output(13));
    }
}
#endif