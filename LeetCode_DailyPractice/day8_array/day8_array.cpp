// leetcode 209 动态窗口法
#include <iostream>
#include <vector>

// 本解法的关键是跳出暴力解法的思维领域，先固定结束指针的位置（满足sum>=target），再向后移动起始指针（看是否满足sum>=target）以找到该区间上的最小区间
using namespace std;
class Solution{
public:
    int minSubArrayLen(int target, vector<int>nums){
        int result = INT32_MAX;                                   // 连续数组的长度要取最小，必须要和取最大比较，依次去缩小     
        int subLenth = 0;                                         // 记录当前字符子串的长度
        int sum = 0;                                              // 记录求和的值
        int start = 0;                                            // 记录子串的起始位置
        for(int end = 0; end < nums.size();++end){                // 记录子串的终止位置
            sum += nums[end];                      
            while(sum >= target){                                 // 找到了满足要求的子串
               subLenth = end - start + 1;                         
               result = result < subLenth ? result : subLenth;    // 比较当前子串和上一次记录的子串谁更短
               sum -= nums[start ++];                             // 向后移动起始位置，看当前子串能否再缩短
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};