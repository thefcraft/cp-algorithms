// @ignore tfmeta: eyJzaW5nbGVfdGVzdF9jYXNlIjogdHJ1ZSwgImZtdF9pbXBvcnRzIjogWyJkaXNwbGF5LmgiLCAiZXh0cmEudGVzdC5hc3NlcnQuaCIsICJleHRyYS5hcnJheS5oIiwgInBhaXIuaCJdLCAiaW9fZmlsZXMiOiBmYWxzZX0=
// author: [Laksh Kumar Sisodiya](https://github.com/thefcraft)
// please run `git clone https://github.com/thefcraft/fmt-display-cpp.git`
// and then copy pase `test.assert.h` file and `fmt` dir to the current folder
// and rename .cp.base_template.cpp to main.cpp and modify it to make your own template and enjoy :-)
// pase input text in `.in.txt`
// get output inside `.out.txt`


#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

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

// int bsearch(ll item, vector<ll> &vec){
//     int start = 0;
//     int end = vec.size() - 1;
//     while (start <= end){
//         int m = start + ((end - start) / 2);
//         if (vec[m] < item) start = m + 1;
//         else if (vec[m] > item) end = m - 1;
//         else return m;
//     }
//     return -1;
// }

// int modified_bsearch(int item, vector<int> &vec, vector<bool> &vec_mask, int length = -1){
//     int start = 0;
//     int end = (length==-1?vec.size() - 1:length);
//     while (start <= end){
//         int m = start + ((end - start) / 2);
//         if (vec[m] < item) start = m + 1;
//         else if (vec[m] > item) end = m - 1;
//         else if (!vec_mask[m]) return m;
//         else {
//             for (int i = m - 1; i >= 0; i--) if (!vec_mask[i]) return i;
//             return -1;            
//         }
//     }
//     if (start + ((end - start) / 2) == 0 && vec[0] > item) return -1;
//     for (int i = start + ((end - start) / 2) - 1; i >= 0; i--) if (!vec_mask[i]) return i;
//     return -1;
// }



// TODO: JUST CODE HERE
// void solver(){
//     int input(n, m); 
//     vector<int> H = vector<int>(n);
//     vector<int> T = vector<int>(m);
//     for (int i = 0; i < n; i++) cin>>H[i]; // O(n)
//     for (int i = 0; i < m; i++) cin>>T[i]; // O(m)
//     sort(H.begin(), H.end()); // O(n*logn)
    
//     vector<int> H_unique = vector<int>(n);
//     vector<int> H_freq = vector<int>(n, 0);
//     int unique_num = 0;
//     int unique_last = H[0];
//     H_unique[unique_num] = unique_last;
//     H_freq[unique_num]++;
//     for (int i = 1; i < n; i++){ // O(n) 
//         if (unique_last != H[i]){
//             unique_num++;
//             unique_last = H[i];
//             H_unique[unique_num] = unique_last;
//         }
//         H_freq[unique_num]++;
//     } unique_num ++;
//     vector<bool> H_is_occupied = vector<bool>(unique_num, false);
//     // vector<int> memo = vector<int>(unique_num, -1);
    
//     // TODO: optim need for the case when all values are unique and t is max_unique for all...
//     for (int i = 0; i < m; i++){ // O(m)
//         const int &t = T[i];
//         const int ans = modified_bsearch(t, H_unique, H_is_occupied, unique_num); // need for some optim ...?
//         if (ans != -1){
//             H_freq[ans]--;
//             if (H_freq[ans] == 0)
//                 H_is_occupied[ans] = true;
//             cout<<H_unique[ans]<<nl;
//         }else cout<<-1<<nl;
//     }
// }

void solver(){ // NOTE: use std optimization also use data structures and there algorithms
    int input(n, m); 
    // vector<int> H = vector<int>(n);
    vector<int> T = vector<int>(m);
    map<int, int> H_freq;
    // for (int i = 0; i < n; i++) cin>>H[i]; // O(n)
    for (int i = 0; i < n; i++) {
        int h; cin>>h;
        H_freq[h]++;
    }
    
    for (int i = 0; i < m; i++) cin>>T[i]; // O(m)
    // sort(H.begin(), H.end()); // O(n*logn)

    // int H_freq[n] = {0};
    
    // const std::allocator<std::pair<const int, int>> &__a
    // for (const int &h: H) // O(n) 
        // H_freq[h]++;
    

    // debug(fmt::sprint_array(H_unique, unique_num));
    // debug(fmt::sprint_array(H_freq, unique_num));
    debug(H_freq);
    for (const int &t: T){
        if (H_freq.count(t) && H_freq[t]!=0){ // t is int the map
            cout<<t<<nl;
            if (--H_freq[t] == 0) H_freq.erase(t);
        }else{
            auto it = H_freq.upper_bound(t);
            if (it != H_freq.begin()) {
                --it; // Move to the largest key ≤ t
                cout << it->first << nl;
                if (--(it->second) == 0) H_freq.erase(it->first);
            } else cout<<-1<<nl;
        }
        debug(t);
        debug(H_freq);
    }
    debug(H_freq);
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
    // It(modified_bsearch){
    //     vector<int> H = vector<int>(10);
    //     for (int i = 0; i < 10; i++) H[i] = i;
    //     vector<bool> H_is_occupied = vector<bool>(10, false);
    //     // sort(a, a+n, greater<int>());
    //     for (int i = 0; i <= 9; i++)
    //         asserteq(modified_bsearch(i, H, H_is_occupied), i);
    //     asserteq(modified_bsearch(-1, H, H_is_occupied), -1);
    //     asserteq(modified_bsearch(11, H, H_is_occupied), 9);
    // }
    // It(modified_bsearch){
    //     vector<int> H = vector<int>(5);
    //     vector<bool> H_is_occupied = vector<bool>(5, false);
    //     H[0] = 5;
    //     H[1] = 3;
    //     H[2] = 7;
    //     H[3] = 8;
    //     H[4] = 5;
    //     sort(H.begin(), H.end()); // H = [3, 5, 5, 7, 8]
    //     asserteq(modified_bsearch(7, H, H_is_occupied), 3);
    //     asserteq(modified_bsearch(8, H, H_is_occupied), 4);
    //     asserteq(modified_bsearch(3, H, H_is_occupied), 0);
    //     asserteq(modified_bsearch(10, H, H_is_occupied), 4);
    //     asserteq(modified_bsearch(4, H, H_is_occupied), 0);
    //     asserteq(modified_bsearch(-1, H, H_is_occupied), -1);
    // }
    It(sample test case){
        tin.set("5 3");
        tin.set("5 3 7 8 5");
        tin.set("4 8 3");
        solver();
        asserttout("3\n8\n-1\n");
    }
    It(failed){
        tin.set("10 10");
        tin.set("1 1 1 1 1 1 1 1 1 1");
        tin.set("1 1 1 1 1 1 1 1 1 1");
        solver();
        asserttout("1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n");
    }
}
#endif