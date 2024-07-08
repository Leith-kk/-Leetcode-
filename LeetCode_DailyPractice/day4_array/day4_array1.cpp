// leetcode 367
#include <iostream>

using namespace std;

class Solution {
public:
    // 二分法查找
    bool isPerfectSquare(int num) {
        bool isPerfectSquare;
        int l = 0, r = num, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= num) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if(ans * ans == num){
            isPerfectSquare = true;
        }else{
            isPerfectSquare = false;
        }
        return isPerfectSquare;
    }

    // Newton法参考ady4_array.cpp文件
};