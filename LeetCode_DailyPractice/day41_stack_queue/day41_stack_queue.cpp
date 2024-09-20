// leetcode 347 前 K 个高频元素
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // 用户自定义的比较类，此处的比较类用于生成小顶堆
    class mycomparison {
    public:
        // 重载operator()函数以自定义比较类
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            // 左大于右即生成了小顶堆，反之是大顶堆（默认也是大顶堆）
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result(k);           // 定义一个大小为k的数组
        unordered_map<int, int> map;

        // 统计数组中元素的出现频率
        for(int i = 0; i < nums.size(); ++i){
            map[nums[i]]++;
        }

        // pair<int, int> 定义了每个元素的类型，即每个元素都是一个包含两个整数的对
        // vector<pair<int, int>> 定义了底层容器类型，即 priority_queue 使用 vector 来存储这些 pair<int, int> 类型的元素
        // mycomparison 是一个自定义的比较类（通常是一个结构体或类），用于定义 priority_queue 中元素的比较方式
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;

        for(unordered_map<int, int>::iterator it = map.begin(); it != map.end(); ++it){
            pri_que.push(*it);        // it是一个迭代器，*it是一个键值对
            if (pri_que.size() > k) { // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
                pri_que.pop();
            }
        }

        // 得到的优先级队列按从小到大排序，将其逆序输出到数组中实现从大到小排序
        for(int i = k - 1; i >= 0; --i){
            result[i] = pri_que.top().first;
            pri_que.pop();
        }

        return result;
    }
};