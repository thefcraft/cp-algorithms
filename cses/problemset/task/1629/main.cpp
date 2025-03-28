// @ignore tfmeta: eyJzaW5nbGVfdGVzdF9jYXNlIjogdHJ1ZSwgImZtdF9pbXBvcnRzIjogWyJkaXNwbGF5LmgiLCAiZXh0cmEudGVzdC5hc3NlcnQuaCIsICJleHRyYS5hcnJheS5oIiwgInBhaXIuaCJdLCAiaW9fZmlsZXMiOiBmYWxzZX0=
// author: [Laksh Kumar Sisodiya](https://github.com/thefcraft)
// please run `git clone https://github.com/thefcraft/fmt-display-cpp.git`
// and then copy pase `test.assert.h` file and `fmt` dir to the current folder
// and rename .cp.base_template.cpp to main.cpp and modify it to make your own template and enjoy :-)
// pase input text in `.in.txt`
// get output inside `.out.txt`


#include <iostream>
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
    int input(n); 
    pair<int, int> arr[n];
    for (int i = 0; i < n; i++){
        int start, end;
        cin>>start>>end;
        arr[i] = {start, end};
    }

    sort(arr, arr+n, [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first)
            return a.second < b.second; // If the first element is equal, sort by second element
        return a.first < b.first; // Otherwise, sort by first element
    });

    // pair<int, int> arr_unique_first[n];
    // arr_unique_first[0] = arr[0];
    // int len_unique_first = 1;
    // for (int i = 1; i < n; i++)
    //     if (arr[i-1].first != arr[i].first) arr_unique_first[len_unique_first++] = arr[i];

    // pair<int, int> arr_unique[len_unique_first];
    // int len_unique = 1;
    // arr_unique[0] = arr_unique_first[len_unique_first-1];
    // for (int i = len_unique_first-2; i >= 0; i--)
    //     if (arr_unique_first[i+1].second != arr_unique_first[i].second) arr_unique[len_unique++] = arr_unique_first[i];
    
    // debug(fmt::sprint_array(arr, n));
    // debug(fmt::sprint_array(arr_unique_first, len_unique_first));
    // debug(fmt::sprint_array(arr_unique, len_unique));

    // NOTE: WRONG LOGIC
    // int ans = 0; int last_taken = 0;
    // for (int i = len_unique-1; i >= 1 ; i--){
    //     if (arr_unique[i].second <= arr_unique[i-1].second) continue;
    //     else {
    //         ans++;
    //         last_taken = i;
    //     }
    // }
    // if (ans == 0 || arr_unique[last_taken].second <= arr_unique[0].first) ans++;
    // cout<<ans<<nl;

    
    pair<int, int> arr_unique[n];
    arr_unique[0] = arr[0];
    int len_unique = 1;
    for (int i = 1; i < n; i++)
        if (arr[i-1].first != arr[i].first) arr_unique[len_unique++] = arr[i];

    int ans=1;
    int last_taken = arr_unique[0].second;
    for(int i = 1; i < n ; i++){
        if(arr_unique[i].second <= last_taken) last_taken=arr_unique[i].second; // taking the last one with lowest end time
        else if(arr_unique[i].first >= last_taken){
            ans++;
            last_taken=arr_unique[i].second;
        }
    }
    cout<<ans<<nl;
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
        tin.set("3", 
                "3 5",
                "4 9",
                "5 8"
        );
        solver();
        asserttout("2\n");
    }
    It(sample test case){
        tin.set("4", 
                "3 5",
                "4 9",
                "5 8",
                "6 10"
        );
        solver();
        asserttout("2\n");
    }
    It(sample test case){
        tin.set("6", 
                "3 5",
                "3 4",
                "5 9",
                "6 7",
                "5 7",
                "8 9"
        );
        solver();
        asserttout("3\n");
    }
    It(failed){
        tin.set("10",
                "404 882",
                "690 974",
                "201 255",
                "800 933",
                "525 819",
                "457 601",
                "461 978",
                "832 932",
                "699 804",
                "795 860"
        );
        solver();
        asserttout("4\n");
    }
}
#endif