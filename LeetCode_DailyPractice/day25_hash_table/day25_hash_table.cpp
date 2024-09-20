// leetcode 454  不考虑重复元素，难度降低不少

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution{
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> umap;  // key: 和， value: 和出现的次数 

        // 统计数组1和数组2中所有元素的和，并记录该和出现的次数
        // 之所以统计两个数组的和是因为统计三个数组的时间复杂度为O(n^3)，而统计两个数组的时间复杂度为O(n^2)
        for(int i = 0; i < nums1.size(); ++i){
            for(int j = 0; j < nums2.size(); ++j){
                umap[nums1[i] + nums2[j]]++;
            }
        }

        int count = 0;                                   // 统计和为0的组合数
        for(int i = 0; i < nums3.size(); ++i){
            for(int j = 0; j < nums4.size(); ++j){

                // unored_map查询的复杂度为O(1)
                // 如果和为0 - (nums3[i] + nums4[j])的组合在umap中存在，则将该组合数加到count中
                if(umap.find(0 - (nums3[i] + nums4[j])) != umap.end()){
                    count += umap[0 - (nums3[i] + nums4[j])];
                }
            }
        }
        return count;
    }
};
