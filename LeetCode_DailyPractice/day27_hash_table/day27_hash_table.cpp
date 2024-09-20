// leetcode 18 ����֮��
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());           // ��ԭ�����������

        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > 0 && nums[i] > target) break;     // ��a���м�֦�������ټ�����
            if(i > 0 && nums[i] == nums[i-1]) continue;    // ��aȥ��

            for(int j = i + 1; j < nums.size(); ++j){
                //if(nums[i] + nums[j] > target && target > 0) break;
                if(nums[i] + nums[j] > target && nums[i] + nums[j] > 0) break; // ��b��֦������ִ��Ч��������һ�д��룬�ɼ�֦ȥ���������

                if(j > i + 1 && nums[j] == nums[j - 1]) continue;   // ��bȥ��
                
                // Ѱ��c��dʹ��˫ָ��
                int left = j + 1;
                int right = nums.size() - 1;

                while(left < right){
                    if((long)nums[i] + nums[j] + nums[left] + nums[right] > target) right--;
                    else if((long)nums[i] + nums[j] + nums[left] + nums[right] < target) left++;
                    else{
                        // Ѱ�ҵ�һ���
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        // ��dȥ��
                        while(right > left && nums[right] == nums[right - 1]) right--;
                        // ��cȥ��
                        while(right > left && nums[left] == nums[left + 1]) left++;
                        // ȥ�غ�˫ָ���ƶ������ظ�Ԫ���ϼ���Ѱ���µ�һ���
                        left++;
                        right--;
                    }                  
                }
            }
        }
        return result;
    }
};