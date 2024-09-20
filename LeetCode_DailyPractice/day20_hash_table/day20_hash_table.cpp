// leetcode 242

#include<iostream>

using namespace std;

class Solution{
    public:
    bool isAnagram(string s, string t) {
        int hash[26] = {0};                   // 将数组中的所有元素初始化为 0

        for(int i = 0; i < s.size(); ++i){    // 由ASCII码值来确定对应字母的下标
            hash[(s[i] - 'a')]++;
        }

        for(int i =0;i < t.zise(); ++i){
            hash[t[i] - 'a'] --;
        }

        for(int i = 0; i < hash.size(); ++i){  // 结果中有非0元素就返回false，否则返回true
            if(hash[i] != 0) return false;
        }

        return true;
    }
};