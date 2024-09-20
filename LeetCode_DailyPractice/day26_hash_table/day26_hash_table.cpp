// leetcode 15

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution{
    public:
    // 哈希表法vect
    vector<vector<int>> threeSum(vector<int>& nums){
        unordered_map<int, int> query;
        vector<vector<int>> result;
        
        // 对数组按小到大进行排序，至关重要
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i){
            // 如果当前数大于0，则不可能找到三个数使得它们的和为0
            if (nums[i] > 0) break;

            // 如果当前数和上一个数相同，则跳过，避免基于a的重复解
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            query.clear();

            for (int j = i + 1; j < nums.size(); ++j) {
                int complement = -nums[i] - nums[j];
                if (query.find(complement) != query.end()) {
                    result.push_back({nums[i], complement, nums[j]});
                    // 跳过重复的数
                    while (j + 1 < nums.size() && nums[j] == nums[j + 1]) ++j;
                }
                // 此处的nums[j]对应下次计算时的中间数b，而下次查询的nums[j]则对应计算式的c
                query[nums[j]] = j;
            }
        }
        return result;
    }

    // 双指针法
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> result;
        int left;
        int right;
        
        // 对数组按照从小到大的顺序进行排序
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); ++i){
            // 如果第一个数大于0，则不可能找到三个数使得它们的和为0
            if(nums[i] > 0) return result;

            // 如果当前处理的数和上一个数相同，则会导致a+b+c=0的情况重复，所以直接跳过
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            // 初始化双指针，left和right分别从两端向中间移动
            left = i + 1;
            right = nums.size() - 1;

            // 使用双指针法，寻找两数之和为-nums[i]的组合
            while(left < right){
                // 如果三数之和大于0，则右指针向左移动
                if(nums[i] + nums[left] + nums[right] > 0) right--;
                // 如果三数之和小于0，则左指针向右移动
                else if(nums[i] + nums[left] + nums[right] < 0) left++;
                else {
                    // 如果找到一组解，则将其加入结果集
                    result.push_back(vector<int>{nums[i], nums[left] , nums[right]});
                    // 跳过重复的数，排除针对当前结果集的重复解
                    while(right > left && nums[left] == nums[left + 1]) left++;
                    while(right > left && nums[right] == nums[right - 1]) right--;

                    // 移动双指针寻找下一组解
                    left++;
                    right--;
                }
            }
        }
        return result;
    }
};
