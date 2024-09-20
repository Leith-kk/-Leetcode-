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
            if(nums[i] < 0){                      // �˴���Ϊ >= 0,negativeΪ-1�����������ȫΪ������r�Ѿ�Խ�磬l��������ƽ��ֵ���ǴӴ�С����
                negative = i;
            }else{
                break;
            }
        }
        l = negative;
        r = negative + 1;
        while(l >= 0 || r < nums.size()){
            if(l < 0){
                new_nums.push_back(nums[r]*nums[r]);           // l<0,˵���ұ߶�������ƽ��ֵ���Ѿ�����ƽ��ֵ��С��������
                ++r;
            }
           else if(r == nums.size()){                          // rԽ�磬˵�����ʣ�µĸ���ƽ��ֵС����������ȡ����
                new_nums.push_back(nums[l]*nums[l]);
                --l;
            }
            else if(nums[l] * nums[l] < nums[r] * nums[r]){    // �����ж����
                new_nums.push_back(nums[l]*nums[l]);
                --l;
            }else{
                new_nums.push_back(nums[r]*nums[r]);           // �����ˡ�>=�������
                ++r;
            }
        }
        return new_nums;
    }

    // ˫ָ�뷨�Ƚ�����ֵ��ƽ���ɽ�

};