// leetcode 26
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0;
        int count = 1;           // �ǿ�����������һ��Ԫ��    

        // �ų�������ܹؼ�    
        if(nums.size() == 0){
            return 0;
        }
        for(int right = 0; right < nums.size(); ++right){
            if(nums[right] != nums[left]){
                nums[++left] = nums[right];     // �˴���++left��left�Ѿ���һ�ˣ����ע����left++��left���Ϻ��ټ�һ��������
                count+=1;
            }
        }
        return count;
    }
};