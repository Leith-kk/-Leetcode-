// leetcode 232 用栈实现队列
#include<iostream>
#include<stack>

using namespace std;

class MyQueue {
public:
    stack<int> staIn;
    stack<int> staOut;

    MyQueue() {

    }
    
    // 模拟向队列添加元素
    void push(int x) {
        staIn.push(x);
    }
    
    // 模拟队列弹出元素
    int pop() {
        if(staOut.empty()){
            while(!staIn.empty()){
                staOut.push(staIn.top());
                staIn.pop();
            }
        }
        int result = staOut.top();
        staOut.pop();

        return result;
    }
    
    // 模拟获取队列最开头元素
    // 此处使用pop函数是为了省去再次对staOut判断是否为空和添加元素，实现代码复用
    int peek() {
        int res = this->pop();
        staOut.push(res);

        return res;
    }
    
    // 模拟判断队列是否为空
    bool empty() {
        return staIn.empty() && staOut.empty();
    }
};