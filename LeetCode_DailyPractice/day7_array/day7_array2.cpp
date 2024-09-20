// leetcode 977
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> new_nums;
        int l, r;
        int negative = -1;
        for(int i = 0;i < nums.size();++i){                      
            if(nums[i] < 0){                      // 此处若为 >= 0,negative为-1，如果数组中全为负数，r已经越界，l从右向左，平方值就是从大到小排列
                negative = i;
            }else{
                break;
            }
        }
        l = negative;
        r = negative + 1;
        while(l >= 0 || r < nums.size()){
            if(l < 0){
                new_nums.push_back(nums[r]*nums[r]);           // l<0,说明右边都是正数平方值大，已经满足平方值从小到大排列
                ++r;
            }
           else if(r == nums.size()){                          // r越界，说明左边剩下的负数平方值小，从右向左取即可
                new_nums.push_back(nums[l]*nums[l]);
                --l;
            }
            else if(nums[l] * nums[l] < nums[r] * nums[r]){    // 正常判断情况
                new_nums.push_back(nums[l]*nums[l]);
                --l;
            }else{
                new_nums.push_back(nums[r]*nums[r]);           // 包含了“>=”的情况
                ++r;
            }
        }
        return new_nums;
    }

    // 双指针法比较正负值的平方可解

};