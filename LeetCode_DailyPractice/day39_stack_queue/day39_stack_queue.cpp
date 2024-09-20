// leetcode 150 �沨�����ʽ��ֵ
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution{
    public:
    // ��������������ȼ�
    unordered_map<char, int> precedence = {
        {'+', 1}, {'-', 1},
        {'*', 2}, {'/', 2},
        {'^', 3}
    };

    // �ж��Ƿ�Ϊ������
    bool isOperator(char c) {
        return precedence.find(c) != precedence.end();
    }

    // �ж��Ƿ�Ϊ����
    bool isParenthesis(char c) {
        return c == '(' || c == ')';
    }

    // ����׺���ʽת��Ϊ�沨�����ʽ
    string infixToPostfix(const string& infix) {
        stack<char> operatorStack;
        string postfix;

        for (char c : infix) {
            // ��������ֻ����ַ���ֱ��������ַ���
            if (isdigit(c) || isalpha(c)) {
                postfix += c;                    // C++֧��+=�����������ַ���
            } 
            else if (isOperator(c)) {
                // 1����ջ���Ĳ��������ȼ����ڵ�ǰ��������ջ���������ȼ��㣬��ջ����������ӵ��ַ���ĩβ����������󽫵�ǰ��������ջ
                while (!operatorStack.empty() && isOperator(operatorStack.top()) &&
                    precedence[operatorStack.top()] >= precedence[c]) {
                    postfix += operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.push(c);
            } 

            // 2���������'('��ֱ����ջ
            else if (c == '(') {
                operatorStack.push(c);
            } 

            // 3���������')'����ջ���Ĳ�����������ֱ������'('Ϊֹ
            else if (c == ')') {
                while (!operatorStack.empty() && operatorStack.top() != '(') {
                    postfix += operatorStack.top();
                    operatorStack.pop();
                }
                if (!operatorStack.empty() && operatorStack.top() == '(') {
                    operatorStack.pop();
                }
            }
        }

        // 4���ڱ�����׺���ʽ�����󣬱��в���������ջ�У���Ҫ����ǰջ�еĲ�����ȫ�����
        while (!operatorStack.empty()) {
            postfix += operatorStack.top();
            operatorStack.pop();
        }

        return postfix;
    }

    // ͨ��ջ�������沨�����ʽ��ֵ
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i < tokens.size(); ++ i){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                // ���ظ��Ĳ��赥��������������ڷֱ��ж�ʱ�ظ�����
                int temp_1 = st.top();
                st.pop();
                int temp_2 = st.top();
                st.pop();
                
                // ���ڡ�-���͡�/��������Ҫע��˳����ջ�·��Ĳ��Ǳ������򱻳���
                if(tokens[i] == "+") st.push(temp_2 + temp_1);
                if(tokens[i] == "-") st.push(temp_2 - temp_1);
                if(tokens[i] == "*") st.push(temp_2 * temp_1);
                if(tokens[i] == "/"){
                    if(temp_1 == 0) cout << "The divisor is 0!" << endl;
                    else st.push(temp_2 / temp_1);
                }
            }
            
            else st.push(stoi(tokens[i]));   // stoi()�����ǽ��ַ���stringת��(to)Ϊ������(int)����������Ϊȡ�������ʵ�����ĸ
        }

        return st.top();
    }
};

int main(){
    string s = "a ^ 2 + b ^ 2 + (4 - a) * (5 - b) ^ 2 / 3";
    Solution test;
    cout << test.infixToPostfix(s) << endl;

    return 0;
}