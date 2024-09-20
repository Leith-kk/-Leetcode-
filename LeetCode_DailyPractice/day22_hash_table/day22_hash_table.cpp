// leetcode 350

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>    // 为了使用 min 函数

using namespace std;

class Solution{
    public:
    // 使用数组作为哈希表
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2){
        vector<int> result(1001,0);
        vector<int> arr1(1001,0);
        vector<int> arr2(1001,0);

        // 记录nums1中的数字出现次数
        for(int num : nums1){
            arr1[num] += 1;
        }

        // 记录nums2与nums1的交集
        arr2 = arr1;
        for(int num : nums2){
            arr2[num] -= 1;
        }

        // 将交集写入result
        for(int i = 0; i < arr1.size(); ++i){
            if(arr1[i] == arr2[i]) continue;
            else{
                // arr2[i] >=0 表示nums2中该数字出现次数少
                if(arr2[i] >=0) result.insert(result.end(), arr1[i] - arr2[i], i);
                // arr2[i] < 0 表示nums1中该数字出现次数少
                if(arr2[i] < 0) result.insert(result.end(), arr1[i], i);
            }
        }
        return result; 
    }

    // 使用unordered_map作为哈希表
    vector<int> intersects(vector<int>& nums1, vector<int>& nums2){
        vector<int> result;
        unordered_map<int,int> count1;
        unordered_map<int,int> count2;

        // 记录两个数组中元素的出现次数
        for(int num : nums1) count1[num]++;
        for(int num : nums2) count2[num]++;

        // 寻找交集，重复元素取较少的一组
        for (const auto& pair : count1){
            int num = pair.first;

            int count = min(pair.second, count2[num]);
            result.insert(result.end(), count, num);
        }
        return result;
    }  
};

// 实际验证
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
