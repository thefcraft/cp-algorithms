// @ignore tfmeta: eyJzaW5nbGVfdGVzdF9jYXNlIjogdHJ1ZSwgImZtdF9pbXBvcnRzIjogWyJkaXNwbGF5LmgiLCAiZXh0cmEudGVzdC5hc3NlcnQuaCIsICJleHRyYS5hcnJheS5oIl0sICJpb19maWxlcyI6IGZhbHNlfQ==
// author: [Laksh Kumar Sisodiya](https://github.com/thefcraft)
// please run `git clone https://github.com/thefcraft/fmt-display-cpp.git`
// and then copy pase `test.assert.h` file and `fmt` dir to the current folder
// and rename .cp.base_template.cpp to main.cpp and modify it to make your own template and enjoy :-)
// pase input text in `.in.txt`
// get output inside `.out.txt`


#include <iostream>
#include <map>

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

template <typename T, typename Key>
bool key_exists(const T& container, const Key& key)
{
    return (container.find(key) != end(container));
}
bool isPrime(ll n){    
    if (n<2) return false;
    else if (n!=2 && n%2==0) return false;
    for (ll i = 3; i*i <= n; i+=2) if (n%i==0) return false;
    return true;
}

map<int, int> primeFactorization(int n) {
    map<int, int> factors;
    int temp = 2;
    while (temp <= n){
        if (n%temp==0 && isPrime(temp)){
            if (key_exists(factors, temp)){
                factors[temp]++;
            }else{
                factors[temp] = 1;
            }
            n/= temp;
        }else temp ++;
    }
    return factors;
}

ll lcm(int *arr, int n){
    int max_arr = 0;
    for (int i = 0; i < n; i++) if (arr[i] > max_arr) max_arr = arr[i];
    int **buffer = new int*[n];
    for (int idx = 0; idx < n; idx++){
        buffer[idx] = new int[max_arr];
        for (int i = 0; i < max_arr; i++) buffer[idx][i] = 0;
    }
    for (int idx = 0; idx < n; idx++){
        int ai = arr[idx];
        int temp = 2;
        while (temp <= ai){
            if (ai%temp==0 && isPrime(temp)){
                buffer[idx][temp]+=1;
                ai/= temp;
            }else temp ++;
        }
    }
    ll result = 1;
    for (int i = 0; i < max_arr; i++){
        bool stop = false;
        while (!stop){
            stop = true;
            bool already_used = false;
            for (int j = 0; j < n; j++) if (buffer[j][i]){
                if (!already_used){
                    result *= i;
                    already_used = true;
                }
                buffer[j][i]--;
                stop = false;
            }
        }
    }
    for (int idx = 0; idx < n; idx++) delete[] buffer[idx];
    delete[] buffer;
    return result;
}

ll lcmV2(int *arr, int n){
    map<int, int> *buffer = new map<int, int>[n];
    for (int idx = 0; idx < n; idx++) buffer[idx] = primeFactorization(arr[idx]);
    map<int, int> res;
    for (int idx = 0; idx < n; idx++){
        map<int, int>::iterator it = buffer[idx].begin();
        while (it != buffer[idx].end()) {
            if (key_exists(res, it->first)){
                if (res[it->first]<it->second) res[it->first] = it->second;
            }else res[it->first] = it->second;
            ++it;
        }
    }
    ll result = 1;
    map<int, int>::iterator it = res.begin();
    while (it != res.end()) {
        for (int i = 0; i < it->second; i++) result*=it->first;
        ++it;
    }
    delete [] buffer;
    return result;
}
// TODO: JUST CODE HERE
void solver(){
    // int input(n, m, k); 
    // int inputn(arr, n);
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    cout<<lcm(arr,20)<<endl;
    cout<<lcmV2(arr, 20)<<endl;
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
        asserttout("232792560\n232792560\n");
    }
}
#endif