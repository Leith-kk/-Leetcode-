// leetcode 459
#include<iostream>

using namespace std;

class Solution {
public:
    // 使用KMP求解next数组
    void getNext(int *next, const string &s){
        next[0] = 0;
        int j = 0;
        for(int i = 1; i < s.size(); ++i){
            while(j > 0 && s[i] != s[j]){
                j = next[j - 1];
            }
            if(s[i] == s[j]){
                ++j;
            }
            next[i] = j;
        }
    }
    
    
    bool repeatedSubstringPattern(string s) {
        if(s.size() == 0) return false;

        int *next = new int[s.size()];
        // vector<int> next(s.size());
        getNext(next, s);

        // next数组的最后一位是最大相等前后缀，除去最大相等前后缀即为最小重复单元
        if(next[s.size() - 1] != 0 && s.size() % (s.size() - next[s.size() - 1]) == 0) return true;
          
        return false;

        // 以下更符合代码规范
        //bool result = (next[s.size() - 1] != 0 && s.size() % (s.size() - next[s.size() - 1]) == 0);  
  
        //delete[] next;  // 释放整数数组  
        //return result;
    }
};

int main(){
    string s = "abcabcabcac";
    Solution test;
    cout << test.repeatedSubstringPattern(s);

    return 0;
}
