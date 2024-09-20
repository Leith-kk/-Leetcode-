// leetcode 28
#include<iostream>

using namespace std;

class Solution{
    public:
    // 朴素模式匹配
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
                  i = i - j;   // 在执行后i还会++一次，所以结束循环后会是i = i - j + 1
                  j = 0;
                  break;
              }
          }
          if(j >= m) return i - j;
      }
      
     return -1;
    }

    // 求子串中每一个小子串的最大相等前后缀表，相当于单独对子串单独执行KMP算法
    void getNext(int *next, string &s){
        int j = 0;                                   // j指向小子串前缀表的末尾，同时也是最大相等前后缀的长度
        next[0] = 0;                                 // 子串的第一位最大相等前后缀始终为0
        for(int i = 1; i < s.size(); ++i){           // i指向小子串后缀表的末尾
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

    // KMP模式匹配
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