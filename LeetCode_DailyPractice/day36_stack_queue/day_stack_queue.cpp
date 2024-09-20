// leetcode 225 用队列实现栈
#include<iostream>
#include<queue>

using namespace std;

class MyStack {
public:
    queue<int> q;
    MyStack() {

    }
    
    // 模拟入栈
    void push(int x) {
        q.push(x);
    }

    // 模拟出栈
    int pop() {
        // 将队列中最后一个元素之前的所有元素出队后重新入队，此时队首元素为栈顶元素
        int size = q.size() - 1;
        while(size--){
            // int temp = q.pop();   C++队列pop无返回值
            // q.push(temp);
            q.push(q.front());
            q.pop();
        }
        // 将队首（栈顶）出队（出栈）
        int res = q.front();
        q.pop();

        return res;
    }
    
    // 模拟获取栈顶元素，调用已经写好的pop函数
    int top() {
        int result = this->pop();
        // 获取栈顶并不删除栈顶，在出栈后将其重新入栈（入队），不破坏原来的数据结构
        q.push(result);

        return result;
    }
    
    bool empty() {
        return q.empty();
    }
};