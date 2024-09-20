// leetcode 26
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0;

        // 排除空数组很关键    
        if(nums.size() == 0){
            return 0;
        }
        for(int right = 0; right < nums.size(); ++right){
            if(nums[right] != nums[left]){
                nums[++left] = nums[right];     // 此处的++left（left已经加一了）很妙，注意与left++（left左结合后再加一）的区别
            }
        }
        return left + 1;     // 返回的是不同元素的个数
    }
};