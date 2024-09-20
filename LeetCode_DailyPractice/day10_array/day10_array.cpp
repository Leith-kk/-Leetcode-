//leetcode 76
#include<iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tmap, smap;       // 用于存放键值对key-value
        int n1 = s.size(),n2 = t.size();

         //如果t串比s串还长，s中肯定不能找到相应的子串
        if(n1<n2) return "";                      

        int left = 0, correct = 0; 
        string res = s;

        // 制作t字符串中字符出现次数的字典
        for (auto item : t)                        // auto关键字用于自动推断item的类型
            ++tmap[item];                          // tmap[item]自动创建，初始值为0

        // 移动窗口法
        for (int right = 0; right < s.size(); ++right) {
            // smap维护的是当前窗口内的字符出现数的字典
            ++smap[s[right]];
            // 当前right对应s的字符是在t中出现的，并且数量上还没有达到冗余，是一次有效添加
            if (tmap[s[right]] >= smap[s[right]])
                ++correct;
            // 字符串最短是空串 && 如果left对应的字符是冗余，那么进行右移删除，同时对left右移
            while (left < right && smap[s[left]] > tmap[s[left]])
                --smap[s[left++]];
            // correct对应有效添加的次数，即t中的字符数
            if(correct == t.size()){
                // 判断当前是否为最短子串
                if (right - left + 1 < res.size())
                    res = s.substr(left,right - left + 1);
            }
        }
        return correct == t.size()? res : "";
    }
};
