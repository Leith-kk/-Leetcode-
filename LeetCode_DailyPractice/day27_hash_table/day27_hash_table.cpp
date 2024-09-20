// leetcode 18 四数之和
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());           // 对原数组进行排序

        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > 0 && nums[i] > target) break;     // 对a进行剪枝处理，减少计算量
            if(i > 0 && nums[i] == nums[i-1]) continue;    // 对a去重

            for(int j = i + 1; j < nums.size(); ++j){
                //if(nums[i] + nums[j] > target && target > 0) break;
                if(nums[i] + nums[j] > target && nums[i] + nums[j] > 0) break; // 对b剪枝处理，其执行效果优于上一行代码，可剪枝去除更多情况

                if(j > i + 1 && nums[j] == nums[j - 1]) continue;   // 对b去重
                
                // 寻找c、d使用双指针
                int left = j + 1;
                int right = nums.size() - 1;

                while(left < right){
                    if((long)nums[i] + nums[j] + nums[left] + nums[right] > target) right--;
                    else if((long)nums[i] + nums[j] + nums[left] + nums[right] < target) left++;
                    else{
                        // 寻找到一组解
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        // 对d去重
                        while(right > left && nums[right] == nums[right - 1]) right--;
                        // 对c去重
                        while(right > left && nums[left] == nums[left + 1]) left++;
                        // 去重后将双指针移动到非重复元素上继续寻找新的一组解
                        left++;
                        right--;
                    }                  
                }
            }
        }
        return result;
    }
};