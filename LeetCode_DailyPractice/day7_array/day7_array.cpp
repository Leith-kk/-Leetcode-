// leetcode 844
#include <iostream>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.length() - 1, j = T.length() - 1;        // 从后往前遍历
        int skipS = 0, skipT = 0;                          // 记录遇到'#'的次数

        while (i >= 0 || j >= 0) {
            // 遍历字符串s
            while (i >= 0) {
                if (S[i] == '#') {
                    skipS++, i--;               // 当前字符为'#'，skipS++，表示多一个要跳过的字符
                } else if (skipS > 0) {         // 当前字符不为'#'，有两种情况，要么跳过，要么保留与字符串t做对比
                    skipS--, i--;               // 情况1：skipS > 0，该字符跳过
                } else {
                    break;                      // 情况2：skipS = 0，该字符用来与字符串t比较，跳出小循环进入比较的大循环
                }
            }

            // 对字符串T执行与字符串S相同的操作
            while (j >= 0) {
                if (T[j] == '#') {
                    skipT++, j--;
                } else if (skipT > 0) {
                    skipT--, j--;
                } else {
                    break;
                }
            }

            // 比较两个存在字符串中且没有被消除的非'#'字符
            if (i >= 0 && j >= 0) {           // 字符串S、T都没有截止时进入对比，都截止了说明已经（遍历+对比）结束了，返回true就行了
                if (S[i] != T[j]) {           // 不相等直接false，程序终止
                    return false;
                }
            } else {                          // 有一个字符串已经截止，但另一个字符串还未截止，不需要再比较，肯定不相等
                if (i >= 0 || j >= 0) {
                    return false;
                }
            }

            // 一次比较结束，再去遍历前面的字符
            i--, j--;
        }
        return true;
    }
};