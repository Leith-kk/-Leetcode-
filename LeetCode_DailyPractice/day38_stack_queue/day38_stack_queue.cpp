// leetcode 1047 删除字符串中的所有相邻重复项

#include<iostream>
#include<stack>

using namespace std;

class Solution{
    public:
    string removeDuplicates(string s) {
        stack<char> st;
        // 将已经遍历的元素压入栈中
        for(int i = 0; i < s.size(); ++i){
            if(!st.empty() && st.top() == s[i]) st.pop();
            else st.push(s[i]);
        }

        // 栈弹出的元素为倒序，从字符串末尾向前修改源字符串，节省空间
        int j = s.size() - 1;
        while(!st.empty()){
            s[j--] = st.top();
            st.pop();
        }
        s = s.substr(j + 1, s.size() - 1);   // 截取字符串的一部分

        return s;
    }
};