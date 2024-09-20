// leetcode 1
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
    public:
    // �������, ���Ӷ�O(n^2)
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> index;
        for(int i = 0; i < nums.size(); ++i){
            for(int j = i + 1; j < nums.size(); ++j){          // ��ǰ�±�֮ǰ��Ԫ���Ѿ��뵱ǰԪ��ƥ���������Ҫ��ƥ��
                if(nums[i] + nums[j] == target) return {i,j};
            }
        }
        return {};
    }

    // ʹ�ù�ϣ�����Ӷ�O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;             // ��ϣ����Ϊ����Ԫ�أ�ֵΪԪ�ص�����
        for(int i = 0; i < nums.size(); ++i){
            // �ڹ�ϣ��������ָ���ļ���
            // ����ҵ��˼������᷵��һ��ָ��ü�ֵ�Եĵ����������û���ҵ����򷵻� map.end()
            // ÿ�ζ����Ȳ��ң��ٲ��룬��˶����ظ�Ԫ�أ�ֻ�����һ��
            auto iter = map.find(target - nums[i]);
            if(iter != map.end()){
                return {iter->second, i};
            }
            else{
                // ����ǰԪ�غ������������뵽��ϣ����
                map.insert(pair<int, int>(nums[i], i));
            }
        }
        return {};
    }
};