// leetcode 15

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution{
    public:
    // ��ϣ��vect
    vector<vector<int>> threeSum(vector<int>& nums){
        unordered_map<int, int> query;
        vector<vector<int>> result;
        
        // �����鰴С�����������������Ҫ
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i){
            // �����ǰ������0���򲻿����ҵ�������ʹ�����ǵĺ�Ϊ0
            if (nums[i] > 0) break;

            // �����ǰ������һ������ͬ�����������������a���ظ���
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            query.clear();

            for (int j = i + 1; j < nums.size(); ++j) {
                int complement = -nums[i] - nums[j];
                if (query.find(complement) != query.end()) {
                    result.push_back({nums[i], complement, nums[j]});
                    // �����ظ�����
                    while (j + 1 < nums.size() && nums[j] == nums[j + 1]) ++j;
                }
                // �˴���nums[j]��Ӧ�´μ���ʱ���м���b�����´β�ѯ��nums[j]���Ӧ����ʽ��c
                query[nums[j]] = j;
            }
        }
        return result;
    }

    // ˫ָ�뷨
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> result;
        int left;
        int right;
        
        // �����鰴�մ�С�����˳���������
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); ++i){
            // �����һ��������0���򲻿����ҵ�������ʹ�����ǵĺ�Ϊ0
            if(nums[i] > 0) return result;

            // �����ǰ�����������һ������ͬ����ᵼ��a+b+c=0������ظ�������ֱ������
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            // ��ʼ��˫ָ�룬left��right�ֱ���������м��ƶ�
            left = i + 1;
            right = nums.size() - 1;

            // ʹ��˫ָ�뷨��Ѱ������֮��Ϊ-nums[i]�����
            while(left < right){
                // �������֮�ʹ���0������ָ�������ƶ�
                if(nums[i] + nums[left] + nums[right] > 0) right--;
                // �������֮��С��0������ָ�������ƶ�
                else if(nums[i] + nums[left] + nums[right] < 0) left++;
                else {
                    // ����ҵ�һ��⣬�����������
                    result.push_back(vector<int>{nums[i], nums[left] , nums[right]});
                    // �����ظ��������ų���Ե�ǰ��������ظ���
                    while(right > left && nums[left] == nums[left + 1]) left++;
                    while(right > left && nums[right] == nums[right - 1]) right--;

                    // �ƶ�˫ָ��Ѱ����һ���
                    left++;
                    right--;
                }
            }
        }
        return result;
    }
};
