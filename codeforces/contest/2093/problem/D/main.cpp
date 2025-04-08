// @ignore tfmeta: eyJzaW5nbGVfdGVzdF9jYXNlIjogZmFsc2UsICJmbXRfaW1wb3J0cyI6IFsiZGlzcGxheS5oIiwgImV4dHJhLnRlc3QuYXNzZXJ0LmgiLCAiZXh0cmEuYXJyYXkuaCIsICJwYWlyLmgiLCAidHVwbGUuaCJdLCAiaW9fZmlsZXMiOiBmYWxzZX0=
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
		#include XSTR(FMTDISPLAYPATH_BASE/tuple.h)
    #else
        // #include "fmt/display.h" // https://github.com/thefcraft/fmt-display-cpp/tree/main/fmt
        // #include "fmt/extra.test.assert.h" // https://github.com/thefcraft/fmt-display-cpp/blob/main/test.assert.h
        #include "fmt/display.h"
		#include "fmt/extra.test.assert.h"
		#include "fmt/extra.array.h"
		#include "fmt/pair.h"
		#include "fmt/tuple.h"
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


pair<ull, ull> square_number_smaller_then_or_equal(ull n){ // NOTE: it also return 2
    // if (n==0 || n==1 || n==2 || n == 3) return {1, 1};
    
    ull j = 1;
    ull t = 0;
    while(n>1){
        n>>=1;
        j<<=1;
        t++;
    }
    return {j, t};
}

ull solver_first_0idx(ull x, ull y){
    if (x == 0 && y == 0) return 1;
    if (x == 1 && y == 1) return 2;
    if (x == 1 && y == 0) return 3;
    if (x == 0 && y == 1) return 4;

    pair<ull, ull> kx = square_number_smaller_then_or_equal(x);
    pair<ull, ull> ky = square_number_smaller_then_or_equal(y);
    // btw n = max(second) + 1
    
    // TODO handle case in which kx.first == x or ky.first == y
    if (kx.first == ky.first){
        // bottom-right
        ull offset = kx.first*kx.first; // SOME BUG: as kx.first at max 60 but this is not the case here 
        return offset + solver_first_0idx(x-kx.first, y-ky.first);
    }else if(kx.first < ky.first){
        // top-right
        ull offset = ky.first*ky.first;
        return offset*3 + solver_first_0idx(x, y-ky.first);
    // }else if(kx.first > ky.first){
    }else{
        // bottom-left
        ull offset = kx.first*kx.first;
        return offset*2 + solver_first_0idx(x-kx.first, y);
    }
}
ull solver_first(ull x, ull y){
    return solver_first_0idx(x-1, y-1);
}

pair<ull, ull> solver_second_0idx(ull q){
    if (q == 0) return {0, 0};
    if (q == 1) return {1, 1};
    if (q == 2) return {1, 0};
    if (q == 3) return {0, 1};
   
    
    pair<ull, ull> kq = square_number_smaller_then_or_equal(q);
    
    // 7 => kq = {4, 2}
    if (kq.second%2 == 0){
        // bottom-right
        // debug("bottom-right");
        pair<ull, ull> ans = solver_second_0idx(q-kq.first);
        return {ans.first + (1ULL<<(kq.second>>1)), ans.second + (1ULL<<(kq.second>>1))};
    }
    ull size_of_quartor = kq.first>>1;
    if (q < size_of_quartor*3){
        // bottom-left
        // debug("bottom-left");
        // debug(kq.second);
        pair<ull, ull> ans = solver_second_0idx(q-kq.first);
        return {ans.first + (1ULL<<((kq.second - 1)>>1)), ans.second};
    }
    // top-right
    // debug("top-right");
    // debug(kq.second);
    pair<ull, ull> ans = solver_second_0idx(q-kq.first-size_of_quartor);
    return {ans.first, ans.second + (1ULL<<((kq.second - 1)>>1))};
}

pair<ull, ull> solver_second(ull q){
    pair<ull, ull> ans = solver_second_0idx(q-1);
    return {ans.first+1, ans.second+1};
}

// TODO: JUST CODE HERE
void solver(){
    int input(n, q); 
    while (q--){
        char input(c1, c2);
        if (c1 == '-' && c2 == '>'){
            ull input(x, y);
            cout<<solver_first(x, y)<<nl;
        }else if(c1 == '<' && c2 == '-'){
            ull input(d);
            pair<ull, ull> ans = solver_second(d);
            cout<<ans.first<<' '<<ans.second<<nl;
        }else
            debug("unlikely");
    }
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
MAKE_TESTS{
    // It(grid){
    //     for (int i = 1; i <= 16; i++){
    //         if ((i-1)%4 == 0) std::cerr<<nl;
    //         for (int j = 1; j <= 16; j++){
    //             if ((j-1)%4 == 0) std::cerr<<' ';
    //             int ans = solver_first(i, j);
    //             pair<int, int> rev_ans = solver_second(ans);
    //             // if (ans<10) std::cerr<<'0';
    //             // if (ans<100) std::cerr<<'0';

    //             // if ((rev_ans.first<10) && (rev_ans.second<10)) std::cerr<<ans<<"[0"<<rev_ans.first<<",0"<<rev_ans.second<<"]"<<", ";
    //             // else if (rev_ans.first<10) std::cerr<<ans<<"[0"<<rev_ans.first<<","<<rev_ans.second<<"]"<<", ";
    //             // else if (rev_ans.second<10) std::cerr<<ans<<"["<<rev_ans.first<<",0"<<rev_ans.second<<"]"<<", ";
    //             // else std::cerr<<ans<<"["<<rev_ans.first<<","<<rev_ans.second<<"]"<<", ";

    //             asserteq(rev_ans.first, i);
    //             asserteq(rev_ans.second, j);
    //         }
    //         // std::cerr<<nl;
    //     }
    //     // std::cerr<<nl;
    // }
    
    It(failed){
        asserteq(solver_first(10, 7), 191);
        asserteq(solver_first(11349, 91987), 13767741741);

        asserteq(fmt::print.sprint(solver_second(191)), "{10, 7}");
        asserteq(fmt::print.sprint(solver_second(13767741741)), "{11349, 91987}");

        asserteq(fmt::print.sprint(solver_second(7)), "{4, 3}");
        // asserteq(fmt::print.sprint(solver_second(8)), "{3, 4}");

        // asserteq(fmt::print.sprint(solver_second(128)), "{9, 16}");

        // asserteq(fmt::print.sprint(solver_second(64)), "{1, 8}");
    }
    // you can use this if you want...
    It(){
        asserteq(square_number_smaller_then_or_equal(12).first, 8);
        asserteq(square_number_smaller_then_or_equal(8).first, 8);
        asserteq(square_number_smaller_then_or_equal(7).first, 4);
        asserteq(square_number_smaller_then_or_equal(3).first, 2);
    }
    It(){
        asserteq(solver_first(4, 3), 7);
        asserteq(solver_first(7, 6), 28);
        asserteq(solver_first(3, 2), 12);
        asserteq(solver_first(1, 8), 64);
        asserteq(solver_first(8, 8), 22);
        asserteq(solver_first(3, 3), 5);

        asserteq(solver_first(1, 4), 16);

        
    }
    It(){
        asserteq(fmt::print.sprint(solver_second(8)), "{3, 4}");
        asserteq(fmt::print.sprint(solver_second(12)), "{3, 2}");
        asserteq(fmt::print.sprint(solver_second(11)), "{4, 1}");
        asserteq(fmt::print.sprint(solver_second(16)), "{1, 4}");
        asserteq(fmt::print.sprint(solver_second(15)), "{2, 3}");
        
        
    }

    It(failed){
        // above 32 it is not working
        // for (int i = 80; i <= 100; i++){
        //     for (int j = 1; j <= 10; j++){
        //         asserteq(fmt::print.sprint(solver_second(solver_first(i, j))), fmt::print.sprint("{", i, ", ", j, "}"));
        //     }
        // }

        
        asserteq(solver_first(4, 6), 58);
        asserteq(fmt::print.sprint(solver_second(58)), "{4, 6}");

        // TODO: overflow in the logic i just did 1<<some insted of 1ULL<<some

        
        // TODO: still overflow i guess, i am doing something wrong, as i can't store it in the memory
        // asserteq(solver_first(65, 67), 4294967353);

        // NOTE: yeah i used 1ULL<<other insted of squaring other
    }

    It(sample test case){
        tin.set("2 5 -> 4 3 <- 15 <- 4 -> 3 1 -> 1 3");
        solver();
        asserttout("7\n2 3\n1 2\n9\n13\n");
    }
}
#endif