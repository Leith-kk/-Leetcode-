// leetcode 541 反转字符串
#include <iostream>
using namespace std;

class Solution{
    public:
    // 暴力讨论
    string reverseStr(string s, int k) {
        // 恰好满足间隔2k个可以反转
        if(s.size() % (2 * k) == 0){
            for(int p = 0; p < s.size(); p += (2 * k)){
                for(int i = p, j = p + k - 1; i < p + k / 2; ++i, --j) swap(s[i], s[j]);
            }
        }

        // 剩余长度小于k
        if(s.size() % (2 * k) < k && s.size() % (2 * k) > 0){
            int p = 0;
            for(; p < (s.size() - s.size() % (2 * k)); p += (2 * k)){
                for(int i = p, j = p + k - 1; i < p + k / 2; ++i, --j) swap(s[i], s[j]);
            }
            for(int i = p, j = s.size() - 1; i < p + (s.size() - p) / 2; ++i, --j) swap(s[i], s[j]);
        }

        // 剩余长度大于等于k且小于2k
        if (k <= s.size() % (2 * k) && s.size() % (2 * k) < (2 * k)){ 
            int p = 0;
            for(; p < (s.size() - s.size() % (2 * k)); p += (2 * k)){
                for(int i = p, j = p + k - 1; i < p + k / 2; ++i, --j) swap(s[i], s[j]);
            }
            for(int i = p, j = p + k - 1; i < p + k / 2; ++i, --j) swap(s[i], s[j]);
        }
        return s;
    }

    // 快速判断,极其优雅
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            // 1. 每隔 2k 个字符的前 k 个字符进行反转
            // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k );   // 也是for循环实现
            } else {
                // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};

int main(){
    string s = "abcd";
    int k = 4;
    Solution str;
    cout << str.reverseStr(s,k) << endl;
    return 0;
}