// leetcode 459
#include<iostream>

using namespace std;

class Solution {
public:
    // ʹ��KMP���next����
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

        // next��������һλ��������ǰ��׺����ȥ������ǰ��׺��Ϊ��С�ظ���Ԫ
        if(next[s.size() - 1] != 0 && s.size() % (s.size() - next[s.size() - 1]) == 0) return true;
          
        return false;

        // ���¸����ϴ���淶
        //bool result = (next[s.size() - 1] != 0 && s.size() % (s.size() - next[s.size() - 1]) == 0);  
  
        //delete[] next;  // �ͷ���������  
        //return result;
    }
};

int main(){
    string s = "abcabcabcac";
    Solution test;
    cout << test.repeatedSubstringPattern(s);

    return 0;
}
