// leetcode 350

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>    // Ϊ��ʹ�� min ����

using namespace std;

class Solution{
    public:
    // ʹ��������Ϊ��ϣ��
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2){
        vector<int> result(1001,0);
        vector<int> arr1(1001,0);
        vector<int> arr2(1001,0);

        // ��¼nums1�е����ֳ��ִ���
        for(int num : nums1){
            arr1[num] += 1;
        }

        // ��¼nums2��nums1�Ľ���
        arr2 = arr1;
        for(int num : nums2){
            arr2[num] -= 1;
        }

        // ������д��result
        for(int i = 0; i < arr1.size(); ++i){
            if(arr1[i] == arr2[i]) continue;
            else{
                // arr2[i] >=0 ��ʾnums2�и����ֳ��ִ�����
                if(arr2[i] >=0) result.insert(result.end(), arr1[i] - arr2[i], i);
                // arr2[i] < 0 ��ʾnums1�и����ֳ��ִ�����
                if(arr2[i] < 0) result.insert(result.end(), arr1[i], i);
            }
        }
        return result; 
    }

    // ʹ��unordered_map��Ϊ��ϣ��
    vector<int> intersects(vector<int>& nums1, vector<int>& nums2){
        vector<int> result;
        unordered_map<int,int> count1;
        unordered_map<int,int> count2;

        // ��¼����������Ԫ�صĳ��ִ���
        for(int num : nums1) count1[num]++;
        for(int num : nums2) count2[num]++;

        // Ѱ�ҽ������ظ�Ԫ��ȡ���ٵ�һ��
        for (const auto& pair : count1){
            int num = pair.first;

            int count = min(pair.second, count2[num]);
            result.insert(result.end(), count, num);
        }
        return result;
    }  
};

// ʵ����֤
int main(){
    vector<int> num1 = {1,2,2,3,1};
    vector<int> num2 = {1,2};

    Solution s;

    vector<int> result = s.intersects(num1, num2);
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
