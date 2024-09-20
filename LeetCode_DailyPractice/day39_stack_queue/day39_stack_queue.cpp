// leetcode 150 逆波兰表达式求值
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution{
    public:
    // 定义操作符的优先级
    unordered_map<char, int> precedence = {
        {'+', 1}, {'-', 1},
        {'*', 2}, {'/', 2},
        {'^', 3}
    };

    // 判断是否为操作符
    bool isOperator(char c) {
        return precedence.find(c) != precedence.end();
    }

    // 判断是否为括号
    bool isParenthesis(char c) {
        return c == '(' || c == ')';
    }

    // 将中缀表达式转换为逆波兰表达式
    string infixToPostfix(const string& infix) {
        stack<char> operatorStack;
        string postfix;

        for (char c : infix) {
            // 如果是数字或者字符，直接输出到字符串
            if (isdigit(c) || isalpha(c)) {
                postfix += c;                    // C++支持+=操作来更新字符串
            } 
            else if (isOperator(c)) {
                // 1、若栈顶的操作符优先级高于当前操作符，栈顶操作符先计算，将栈顶操作符添加到字符串末尾并弹出，随后将当前操作符入栈
                while (!operatorStack.empty() && isOperator(operatorStack.top()) &&
                    precedence[operatorStack.top()] >= precedence[c]) {
                    postfix += operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.push(c);
            } 

            // 2、如果遇到'('，直接入栈
            else if (c == '(') {
                operatorStack.push(c);
            } 

            // 3、如果遇到')'，将栈顶的操作符弹出，直到遇到'('为止
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

        // 4、在遍历中缀表达式结束后，必有操作符还在栈中，需要将当前栈中的操作符全部清出
        while (!operatorStack.empty()) {
            postfix += operatorStack.top();
            operatorStack.pop();
        }

        return postfix;
    }

    // 通过栈来计算逆波兰表达式的值
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i < tokens.size(); ++ i){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                // 将重复的步骤单独拎出来，避免在分别判断时重复处理
                int temp_1 = st.top();
                st.pop();
                int temp_2 = st.top();
                st.pop();
                
                // 对于“-”和“/”操作，要注意顺序，在栈下方的才是被减数或被除数
                if(tokens[i] == "+") st.push(temp_2 + temp_1);
                if(tokens[i] == "-") st.push(temp_2 - temp_1);
                if(tokens[i] == "*") st.push(temp_2 * temp_1);
                if(tokens[i] == "/"){
                    if(temp_1 == 0) cout << "The divisor is 0!" << endl;
                    else st.push(temp_2 / temp_1);
                }
            }
            
            else st.push(stoi(tokens[i]));   // stoi()函数是将字符串string转换(to)为整型数(int)，函数命名为取三个单词的首字母
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