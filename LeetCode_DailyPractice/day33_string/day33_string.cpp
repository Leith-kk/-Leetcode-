// leetcode 28
#include<iostream>

using namespace std;

class Solution{
    public:
    // ����ģʽƥ��
    int strStr(string haystack, string needle){
      int m = needle.size();
      int n = haystack.size();
      int j = 0;
      for(int i = 0; i < n - m; ++i){
          while(i < n && j < m){
              if(haystack[i] == needle[j]){
                  ++i;
                  ++j;
              }
              else{
                  i = i - j;   // ��ִ�к�i����++һ�Σ����Խ���ѭ�������i = i - j + 1
                  j = 0;
                  break;
              }
          }
          if(j >= m) return i - j;
      }
      
     return -1;
    }

    // ���Ӵ���ÿһ��С�Ӵ���������ǰ��׺���൱�ڵ������Ӵ�����ִ��KMP�㷨
    void getNext(int *next, string &s){
        int j = 0;                                   // jָ��С�Ӵ�ǰ׺���ĩβ��ͬʱҲ��������ǰ��׺�ĳ���
        next[0] = 0;                                 // �Ӵ��ĵ�һλ������ǰ��׺ʼ��Ϊ0
        for(int i = 1; i < s.size(); ++i){           // iָ��С�Ӵ���׺���ĩβ
            // 
            while(j > 0 && s[i] != s[j]){
                j = next[j - 1];
            }

            if(s[i] == s[j]){
                ++j;
            }
            
            next[i] = j;
        }
    }

    // KMPģʽƥ��
    int strstr(string haystack, string needle){
        if(needle.size() == 0) {
            return 0;
        }

        int *next = new int[needle.size()];
        getNext(&next[0], needle);
        int j = 0;
        int i;

        for(i = 0; i < haystack.size(); ++i){
            while(j > 0 && haystack[i] != needle[j]){
                j = next[j - 1];
            }

            if(haystack[i] == needle[j]){
                ++j;
            }

            if(j >= needle.size()) return (i - j + 1);
        }

        return -1;
    }
};

int main(){
    string haystack = "sadbutsad";
    string needle = "sad";
    Solution s;
    
    cout << s.strstr(haystack, needle) << endl;

    return 0;
}