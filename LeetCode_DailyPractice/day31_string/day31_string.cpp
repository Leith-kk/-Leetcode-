// leetcode 151
#include<iostream>
using namespace std;

class Solution{
    public:
    // 反转函数，start、end为反转单词部分服务
    void reverse(string &s, int start, int end){
        for(int i = start, j = end; i < j; ++i, --j){
            swap(s[i], s[j]);
        }
    }

    void removeExtraSpace(string &s) {
        // 使用双指针法去除多余空格
        int slow = 0;

        // 去除字符串开头、中间、末尾冗余的空格
         for(int fast = 0; fast < s.size(); ++fast){
            //if(s.size() > 0 && s[fast] != ' ')  s[slow++] = s[fast];
            // if(s.size() > 0 && fast - 1 > 0 && s[fast - 1] != ' ' && s[fast] == ' ') s[slow++] = ' ';
            // 对于字符串最后的连续空格处理存在问题

            // 仅对字符进行处理，空格直接跳过
            if(s[fast] != ' '){
                // 若当前slow不为0，说明前面已经处理过单词，接下来处理的是新单词
                if(slow != 0) s[slow++] = ' ';
                while(s[fast] != ' ' && fast < s.size()) s[slow++] = s[fast++];   // 先将当前位置赋值，后++到下一位置
            }

        }

        s.resize(slow);
    }

    string reverseWords(string s){
        removeExtraSpace(s);
        reverse(s, 0, s.size() - 1);

        int start = 0;

        for(int i = 0; i <= s.size(); ++i)
        {
            // 若遇到空格或字符串末尾，说明已经有一个完整的单词
            if(s[i] == ' ' || i == s.size()){
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }
};

int main(){
    string s;
    Solution test;
    s = "a good   example";
    cout << test.reverseWords(s) << endl;
    
    return 0;
}
