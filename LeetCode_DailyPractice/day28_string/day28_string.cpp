//leetcode 344 反转字符串
#include <iostream>
using namespace std;

class Solution {
public:
    // 双指针法
    void reverseString(vector<char>& s) {
        for(int i = 0, j = s.size() - 1; i < s.size() / 2; ++i, --j){
            swap(s[i],s[j]);
        }
    }
};

void swap(int a, int b){
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
}