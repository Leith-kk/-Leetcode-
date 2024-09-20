// leetcode 1
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
    public:
    // 暴力求解, 复杂度O(n^2)
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> index;
        for(int i = 0; i < nums.size(); ++i){
            for(int j = i + 1; j < nums.size(); ++j){          // 当前下标之前的元素已经与当前元素匹配过，不需要再匹配
                if(nums[i] + nums[j] == target) return {i,j};
            }
        }
        return {};
    }

    // 使用哈希表，复杂度O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;             // 哈希表，键为数组元素，值为元素的索引
        for(int i = 0; i < nums.size(); ++i){
            // 在哈希表中搜索指定的键。
            // 如果找到了键，它会返回一个指向该键值对的迭代器；如果没有找到，则返回 map.end()
            // 每次都是先查找，再插入，因此对于重复元素，只会插入一次
            auto iter = map.find(target - nums[i]);
            if(iter != map.end()){
                return {iter->second, i};
            }
            else{
                // 将当前元素和它的索引插入到哈希表中
                map.insert(pair<int, int>(nums[i], i));
            }
        }
        return {};
    }
};