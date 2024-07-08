// leetcode 904
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 定义哈希表存放键值对
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> trees;                 // 存储键值对

        int left = 0, sum = 0;
        for(int right = 0;right < n; ++right){        // 移动窗口法
            ++trees[fruits[right]];                   // right对应的键值对已存在就++value，若不存在就新建一个键值对然后value++;

            while(trees.size() > 2){                  // 键值对个数大于2
                auto it = trees.find(fruits[left]);   // 循环找到fruits[left]
                --it->second;                         // 相当于value--
                if(it->second == 0){                  // left对应的元素个数为0就剔除left对应键值对
                    trees.erase(it);
                }
                ++left;                               // 移动窗口法移动起始端
            }

            sum = max(sum, right - left + 1);         // 此处为何还要+1？因为窗口中始终只有两种水果
        }
        return sum;
    }
};
