// leetcode 34
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, mid = 0, right = nums.size() - 1;
        int lidx = -1, ridx = -1;                                     // ����ҵ����±�

        // Ѱ����߽�
        while(left <= right){
            mid = left + (right - left) / 2;
            if(nums[mid] == target){
                right = mid - 1;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        if(left > right && left < nums.size() && nums[left] == target)
            lidx = left;

        // Ѱ���ұ߽�    
        left = 0, right = nums.size() - 1;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(nums[mid] == target){
                left = mid + 1;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        if(left > right && right >= 0 && nums[right] == target)
            ridx = right;


        return vector<int>{lidx,ridx};
    }
};