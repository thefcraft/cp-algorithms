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
    ull input(k); 
    
    ull ndigitno = 0;
    ull ndigitnolength = 1;
    ull offset = 0;
    // NOTE: WRONG LOGIC AS WE HAVE TO COMPARE WITH OFFSET
    // for (ull i = 9; i < k; i*=10){
    //     ndigitno += i; 
    //     offset += i * ndigitnolength;
    //     ndigitnolength++;
    // }
    ull currnos = 9;
    while (offset < k){
        ndigitno += currnos;
        offset += (currnos * ndigitnolength);
        ndigitnolength++;
        currnos*=10;
    }
    currnos/=10;
    ndigitnolength--;
    offset -= (currnos * ndigitnolength);
    ndigitno-=currnos;



    debug(ndigitno);
    debug(ndigitnolength);
    debug(offset);
    debug(currnos);

    ull adder = (k - offset - 1)/ndigitnolength;
    ull pos = ndigitnolength - 1 - (k - offset - 1)%ndigitnolength;
    debug(adder);
    debug(pos);
    ull ans = ndigitno + 1 + adder;
    for (int i = 0; i < pos; i++) ans/=10;
    ans%=10;
    debug(ans);
    cout<<ans<<nl;
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

    unsigned int t;
    cin >> t;
    while (t--) solver();
    return 0;
}

// sort(a, a+n, greater<int>());
// sort(a, a+n);

#ifdef DEBUG
MAKE_TESTS{
    // you can use this if you want...
    It(1){
        tin.set("1");
        solver();
        asserttout("1\n");
    }
    It(19){
        tin.set("19");
        solver();
        asserttout("4\n");
    }
    It(9){
        tin.set("9");
        solver();
        asserttout("9\n");
    }
    It(10){
        tin.set("10");
        solver();
        asserttout("1\n");
    }
    It(11){
        tin.set("11");
        solver();
        asserttout("0\n");
    }
    It(12){
        tin.set("12");
        solver();
        asserttout("1\n");
    }
    It(13){
        tin.set("13");
        solver();
        asserttout("1\n");
    }
    It(190){
        tin.set("190");
        solver();
        asserttout("1\n");
    }
    It(191){
        tin.set("191");
        solver();
        asserttout("0\n");
    }
    It(193){
        tin.set("193");
        solver();
        asserttout("1\n");
    }
    It(188){
        tin.set("188");
        solver();
        asserttout("9\n");
    }
    It(189){
        tin.set("189");
        solver();
        asserttout("9\n");
    }
    
}
#endif