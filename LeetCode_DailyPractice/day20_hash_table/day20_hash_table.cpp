// leetcode 242

#include<iostream>

using namespace std;

class Solution{
    public:
    bool isAnagram(string s, string t) {
        int hash[26] = {0};                   // �������е�����Ԫ�س�ʼ��Ϊ 0

        for(int i = 0; i < s.size(); ++i){    // ��ASCII��ֵ��ȷ����Ӧ��ĸ���±�
            hash[(s[i] - 'a')]++;
        }

        for(int i =0;i < t.zise(); ++i){
            hash[t[i] - 'a'] --;
        }

        for(int i = 0; i < hash.size(); ++i){  // ������з�0Ԫ�ؾͷ���false�����򷵻�true
            if(hash[i] != 0) return false;
        }

        return true;
    }
};