// leetcode 239 滑动窗口最大值
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

/*
单调队列可以作为一个单独的数据结构
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

}；
*/

class Solution {
private:
    // 使用单调队列实现窗口取最大值
    // 对于队列，其默认底层实现是双向队列dequeue
    // 对于栈，其默认底层实现也是双向队列dequeue
    deque<int> deq;

    // 若要弹出的元素与队首的元素相同，则弹出，若不相同，说明在入队构造单调队列时已经被弹出了
    void pop(int val){
        if(!deq.empty() && val == deq.front()){
            deq.pop_front();
        }
    }

    // 若当前元素大于队尾元素，则将队尾元素弹出，直到遇到比当前元素大的值则停止弹出，将当前元素插入队尾
    void push(int val){
        while(!deq.empty() && val > deq.back()){
            deq.pop_back();
        }

        deq.push_back(val);
    }

    // 获取当前队列中的最大值,其实队首的元素即为最大值
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
            // result.push_back(front());   这里获取的是上一个窗口的的最大值，会丢掉最后一个窗口的最大值，导致输出错误
            
            // que.pop(nums[i - k]);
            // que.push(nums[i]);
            pop(nums[i - k]);
            push(nums[i]);
            result.push_back(front());
        }

        return result;
    }
};

