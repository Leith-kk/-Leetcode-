// leetcode 904
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // �����ϣ���ż�ֵ��
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> trees;                 // �洢��ֵ��

        int left = 0, sum = 0;
        for(int right = 0;right < n; ++right){        // �ƶ����ڷ�
            ++trees[fruits[right]];                   // right��Ӧ�ļ�ֵ���Ѵ��ھ�++value���������ھ��½�һ����ֵ��Ȼ��value++;

            while(trees.size() > 2){                  // ��ֵ�Ը�������2
                auto it = trees.find(fruits[left]);   // ѭ���ҵ�fruits[left]
                --it->second;                         // �൱��value--
                if(it->second == 0){                  // left��Ӧ��Ԫ�ظ���Ϊ0���޳�left��Ӧ��ֵ��
                    trees.erase(it);
                }
                ++left;                               // �ƶ����ڷ��ƶ���ʼ��
            }

            sum = max(sum, right - left + 1);         // �˴�Ϊ�λ�Ҫ+1����Ϊ������ʼ��ֻ������ˮ��
        }
        return sum;
    }
};
