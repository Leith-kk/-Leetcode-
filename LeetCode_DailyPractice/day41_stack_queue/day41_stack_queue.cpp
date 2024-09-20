// leetcode 347 ǰ K ����ƵԪ��
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // �û��Զ���ıȽ��࣬�˴��ıȽ�����������С����
    class mycomparison {
    public:
        // ����operator()�������Զ���Ƚ���
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            // ������Ҽ�������С���ѣ���֮�Ǵ󶥶ѣ�Ĭ��Ҳ�Ǵ󶥶ѣ�
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result(k);           // ����һ����СΪk������
        unordered_map<int, int> map;

        // ͳ��������Ԫ�صĳ���Ƶ��
        for(int i = 0; i < nums.size(); ++i){
            map[nums[i]]++;
        }

        // pair<int, int> ������ÿ��Ԫ�ص����ͣ���ÿ��Ԫ�ض���һ���������������Ķ�
        // vector<pair<int, int>> �����˵ײ��������ͣ��� priority_queue ʹ�� vector ���洢��Щ pair<int, int> ���͵�Ԫ��
        // mycomparison ��һ���Զ���ıȽ��ࣨͨ����һ���ṹ����ࣩ�����ڶ��� priority_queue ��Ԫ�صıȽϷ�ʽ
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;

        for(unordered_map<int, int>::iterator it = map.begin(); it != map.end(); ++it){
            pri_que.push(*it);        // it��һ����������*it��һ����ֵ��
            if (pri_que.size() > k) { // ����ѵĴ�С������K������е�������֤�ѵĴ�СһֱΪk
                pri_que.pop();
            }
        }

        // �õ������ȼ����а���С�������򣬽������������������ʵ�ִӴ�С����
        for(int i = k - 1; i >= 0; --i){
            result[i] = pri_que.top().first;
            pri_que.pop();
        }

        return result;
    }
};