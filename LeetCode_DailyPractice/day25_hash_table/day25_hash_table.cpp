// leetcode 454  �������ظ�Ԫ�أ��ѶȽ��Ͳ���

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution{
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> umap;  // key: �ͣ� value: �ͳ��ֵĴ��� 

        // ͳ������1������2������Ԫ�صĺͣ�����¼�úͳ��ֵĴ���
        // ֮����ͳ����������ĺ�����Ϊͳ�����������ʱ�临�Ӷ�ΪO(n^3)����ͳ�����������ʱ�临�Ӷ�ΪO(n^2)
        for(int i = 0; i < nums1.size(); ++i){
            for(int j = 0; j < nums2.size(); ++j){
                umap[nums1[i] + nums2[j]]++;
            }
        }

        int count = 0;                                   // ͳ�ƺ�Ϊ0�������
        for(int i = 0; i < nums3.size(); ++i){
            for(int j = 0; j < nums4.size(); ++j){

                // unored_map��ѯ�ĸ��Ӷ�ΪO(1)
                // �����Ϊ0 - (nums3[i] + nums4[j])�������umap�д��ڣ��򽫸�������ӵ�count��
                if(umap.find(0 - (nums3[i] + nums4[j])) != umap.end()){
                    count += umap[0 - (nums3[i] + nums4[j])];
                }
            }
        }
        return count;
    }
};
