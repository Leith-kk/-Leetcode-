// leetcode 239 �����������ֵ
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

/*
�������п�����Ϊһ�����������ݽṹ
class deQueue{
public:
    deque<int> deq;

    void pop(int val){
        if(!deq.empty() && val == deq.front()){
            deq.pop_front();
        }
    }

    void push(int val){
        while(!deq.empty() && val > deq.back()){
            deq.pop_back();
        }

        deq.push_back(val);
    }

    int front(){
        return deq.front();
    }

}��
*/

class Solution {
private:
    // ʹ�õ�������ʵ�ִ���ȡ���ֵ
    // ���ڶ��У���Ĭ�ϵײ�ʵ����˫�����dequeue
    // ����ջ����Ĭ�ϵײ�ʵ��Ҳ��˫�����dequeue
    deque<int> deq;

    // ��Ҫ������Ԫ������׵�Ԫ����ͬ���򵯳���������ͬ��˵������ӹ��쵥������ʱ�Ѿ���������
    void pop(int val){
        if(!deq.empty() && val == deq.front()){
            deq.pop_front();
        }
    }

    // ����ǰԪ�ش��ڶ�βԪ�أ��򽫶�βԪ�ص�����ֱ�������ȵ�ǰԪ�ش��ֵ��ֹͣ����������ǰԪ�ز����β
    void push(int val){
        while(!deq.empty() && val > deq.back()){
            deq.pop_back();
        }

        deq.push_back(val);
    }

    // ��ȡ��ǰ�����е����ֵ,��ʵ���׵�Ԫ�ؼ�Ϊ���ֵ
    int front(){
        return deq.front();
    }

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // deQueue que;
        vector<int> result;
        for(int i = 0; i < k; ++i){
            // que.push(nums[i]);
            push(nums[i]);
        }

        result.push_back(front());

        for(int i = k; i < nums.size(); ++i){
            // result.push_back(front());   �����ȡ������һ�����ڵĵ����ֵ���ᶪ�����һ�����ڵ����ֵ�������������
            
            // que.pop(nums[i - k]);
            // que.push(nums[i]);
            pop(nums[i - k]);
            push(nums[i]);
            result.push_back(front());
        }

        return result;
    }
};

