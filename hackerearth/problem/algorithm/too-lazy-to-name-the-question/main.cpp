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

ull lcm(ull a, ull b){
    if (a > b) utils::swap(a, b);
    for (int i = b; ; i += b) {
        if (i % a  == 0) return i;
    }
}

// TODO: JUST CODE HERE
void solver(){
    ull input(a, b, c); // a != b
    if (a > b) utils::swap(a, b);
    ull x=a, y=b;
    ull ans = x;
    for (int i = 0; i < c; i++){
        if (x<y){
            ans = x;
            x+=a;
        }
        else if (x>y) {
            ans = y;
            y+=b;
        }
        else{
            ans = x;
            x+=a;
            y+=b;
        }
    }
    
    if(ans % a == 0 && ans % b == 0){
        for (ll i = ans; i >= 0; i-=lcm(a, b)) cout<<i<<' '; // not a*b but lcm(a, b)
    }
    else if(ans % b == 0){
        for (ll i = ans; i >= 0; i-=b) cout<<i<<' ';
    }
    else{ // ans % a == 0
        for (ll i = ans; i >= 0; i-=a) cout<<i<<' ';
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
    solver();
    return 0;
}

// sort(a, a+n, greater<int>());
// sort(a, a+n);

#ifdef DEBUG
MAKE_TESTS{
    // you can use this if you want...
    It(sample test case){
        tin.set("3 5 14");
        solver();
        asserttout("30 15 0 ");
    }
    It(sample test case){
        tin.set("3 5 13");
        solver();
        asserttout("27 24 21 18 15 12 9 6 3 0 ");
    }
    It(sample test case){
        tin.set("3 5 12");
        solver();
        asserttout("25 20 15 10 5 0 ");
    }
    It(sample test case){
        tin.set("10 3 10");
        solver();
        asserttout("24 21 18 15 12 9 6 3 0 ");
    }
    It(failed){
        tin.set("1000 7 1000");
        solver();
        asserttout("6958 6951 6944 6937 6930 6923 6916 6909 6902 6895 6888 6881 6874 6867 6860 6853 6846 6839 6832 6825 6818 6811 6804 6797 6790 6783 6776 6769 6762 6755 6748 6741 6734 6727 6720 6713 6706 6699 6692 6685 6678 6671 6664 6657 6650 6643 6636 6629 6622 6615 6608 6601 6594 6587 6580 6573 6566 6559 6552 6545 6538 6531 6524 6517 6510 6503 6496 6489 6482 6475 6468 6461 6454 6447 6440 6433 6426 6419 6412 6405 6398 6391 6384 6377 6370 6363 6356 6349 6342 6335 6328 6321 6314 6307 6300 6293 6286 6279 6272 6265 6258 6251 6244 6237 6230 6223 6216 6209 6202 6195 6188 6181 6174 6167 6160 6153 6146 6139 6132 6125 6118 6111 6104 6097 6090 6083 6076 6069 6062 6055 6048 6041 6034 6027 6020 6013 6006 5999 5992 5985 5978 5971 5964 5957 5950 5943 5936 5929 5922 5915 5908 5901 5894 5887 5880 5873 5866 5859 5852 5845 5838 5831 5824 5817 5810 5803 5796 5789 5782 5775 5768 5761 5754 5747 5740 5733 5726 5719 5712 5705 5698 5691 5684 5677 5670 5663 5656 5649 5642 5635 5628 5621 5614 5607 5600 5593 5586 5579 5572 5565 5558 5551 5544 5537 5530 5523 5516 5509 5502 5495 5488 5481 5474 5467 5460 5453 5446 5439 5432 5425 5418 5411 5404 5397 5390 5383 5376 5369 5362 5355 5348 5341 5334 5327 5320 5313 5306 5299 5292 5285 5278 5271 5264 5257 5250 5243 5236 5229 5222 5215 5208 5201 5194 5187 5180 5173 5166 5159 5152 5145 5138 5131 5124 5117 5110 5103 5096 5089 5082 5075 5068 5061 5054 5047 5040 5033 5026 5019 5012 5005 4998 4991 4984 4977 4970 4963 4956 4949 4942 4935 4928 4921 4914 4907 4900 4893 4886 4879 4872 4865 4858 4851 4844 4837 4830 4823 4816 4809 4802 4795 4788 4781 4774 4767 4760 4753 4746 4739 4732 4725 4718 4711 4704 4697 4690 4683 4676 4669 4662 4655 4648 4641 4634 4627 4620 4613 4606 4599 4592 4585 4578 4571 4564 4557 4550 4543 4536 4529 4522 4515 4508 4501 4494 4487 4480 4473 4466 4459 4452 4445 4438 4431 4424 4417 4410 4403 4396 4389 4382 4375 4368 4361 4354 4347 4340 4333 4326 4319 4312 4305 4298 4291 4284 4277 4270 4263 4256 4249 4242 4235 4228 4221 4214 4207 4200 4193 4186 4179 4172 4165 4158 4151 4144 4137 4130 4123 4116 4109 4102 4095 4088 4081 4074 4067 4060 4053 4046 4039 4032 4025 4018 4011 4004 3997 3990 3983 3976 3969 3962 3955 3948 3941 3934 3927 3920 3913 3906 3899 3892 3885 3878 3871 3864 3857 3850 3843 3836 3829 3822 3815 3808 3801 3794 3787 3780 3773 3766 3759 3752 3745 3738 3731 3724 3717 3710 3703 3696 3689 3682 3675 3668 3661 3654 3647 3640 3633 3626 3619 3612 3605 3598 3591 3584 3577 3570 3563 3556 3549 3542 3535 3528 3521 3514 3507 3500 3493 3486 3479 3472 3465 3458 3451 3444 3437 3430 3423 3416 3409 3402 3395 3388 3381 3374 3367 3360 3353 3346 3339 3332 3325 3318 3311 3304 3297 3290 3283 3276 3269 3262 3255 3248 3241 3234 3227 3220 3213 3206 3199 3192 3185 3178 3171 3164 3157 3150 3143 3136 3129 3122 3115 3108 3101 3094 3087 3080 3073 3066 3059 3052 3045 3038 3031 3024 3017 3010 3003 2996 2989 2982 2975 2968 2961 2954 2947 2940 2933 2926 2919 2912 2905 2898 2891 2884 2877 2870 2863 2856 2849 2842 2835 2828 2821 2814 2807 2800 2793 2786 2779 2772 2765 2758 2751 2744 2737 2730 2723 2716 2709 2702 2695 2688 2681 2674 2667 2660 2653 2646 2639 2632 2625 2618 2611 2604 2597 2590 2583 2576 2569 2562 2555 2548 2541 2534 2527 2520 2513 2506 2499 2492 2485 2478 2471 2464 2457 2450 2443 2436 2429 2422 2415 2408 2401 2394 2387 2380 2373 2366 2359 2352 2345 2338 2331 2324 2317 2310 2303 2296 2289 2282 2275 2268 2261 2254 2247 2240 2233 2226 2219 2212 2205 2198 2191 2184 2177 2170 2163 2156 2149 2142 2135 2128 2121 2114 2107 2100 2093 2086 2079 2072 2065 2058 2051 2044 2037 2030 2023 2016 2009 2002 1995 1988 1981 1974 1967 1960 1953 1946 1939 1932 1925 1918 1911 1904 1897 1890 1883 1876 1869 1862 1855 1848 1841 1834 1827 1820 1813 1806 1799 1792 1785 1778 1771 1764 1757 1750 1743 1736 1729 1722 1715 1708 1701 1694 1687 1680 1673 1666 1659 1652 1645 1638 1631 1624 1617 1610 1603 1596 1589 1582 1575 1568 1561 1554 1547 1540 1533 1526 1519 1512 1505 1498 1491 1484 1477 1470 1463 1456 1449 1442 1435 1428 1421 1414 1407 1400 1393 1386 1379 1372 1365 1358 1351 1344 1337 1330 1323 1316 1309 1302 1295 1288 1281 1274 1267 1260 1253 1246 1239 1232 1225 1218 1211 1204 1197 1190 1183 1176 1169 1162 1155 1148 1141 1134 1127 1120 1113 1106 1099 1092 1085 1078 1071 1064 1057 1050 1043 1036 1029 1022 1015 1008 1001 994 987 980 973 966 959 952 945 938 931 924 917 910 903 896 889 882 875 868 861 854 847 840 833 826 819 812 805 798 791 784 777 770 763 756 749 742 735 728 721 714 707 700 693 686 679 672 665 658 651 644 637 630 623 616 609 602 595 588 581 574 567 560 553 546 539 532 525 518 511 504 497 490 483 476 469 462 455 448 441 434 427 420 413 406 399 392 385 378 371 364 357 350 343 336 329 322 315 308 301 294 287 280 273 266 259 252 245 238 231 224 217 210 203 196 189 182 175 168 161 154 147 140 133 126 119 112 105 98 91 84 77 70 63 56 49 42 35 28 21 14 7 0 ");
    }
    It(failed_again){
        tin.set("1000 225 960");
        solver();
        asserttout("180000 171000 162000 153000 144000 135000 126000 117000 108000 99000 90000 81000 72000 63000 54000 45000 36000 27000 18000 9000 0 ");
    }
}
#endif