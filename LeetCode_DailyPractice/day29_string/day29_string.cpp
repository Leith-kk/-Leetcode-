// leetcode 541 ��ת�ַ���
#include <iostream>
using namespace std;

class Solution{
    public:
    // ��������
    string reverseStr(string s, int k) {
        // ǡ��������2k�����Է�ת
        if(s.size() % (2 * k) == 0){
            for(int p = 0; p < s.size(); p += (2 * k)){
                for(int i = p, j = p + k - 1; i < p + k / 2; ++i, --j) swap(s[i], s[j]);
            }
        }

        // ʣ�೤��С��k
        if(s.size() % (2 * k) < k && s.size() % (2 * k) > 0){
            int p = 0;
            for(; p < (s.size() - s.size() % (2 * k)); p += (2 * k)){
                for(int i = p, j = p + k - 1; i < p + k / 2; ++i, --j) swap(s[i], s[j]);
            }
            for(int i = p, j = s.size() - 1; i < p + (s.size() - p) / 2; ++i, --j) swap(s[i], s[j]);
        }

        // ʣ�೤�ȴ��ڵ���k��С��2k
        if (k <= s.size() % (2 * k) && s.size() % (2 * k) < (2 * k)){ 
            int p = 0;
            for(; p < (s.size() - s.size() % (2 * k)); p += (2 * k)){
                for(int i = p, j = p + k - 1; i < p + k / 2; ++i, --j) swap(s[i], s[j]);
            }
            for(int i = p, j = p + k - 1; i < p + k / 2; ++i, --j) swap(s[i], s[j]);
        }
        return s;
    }

    // �����ж�,��������
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            // 1. ÿ�� 2k ���ַ���ǰ k ���ַ����з�ת
            // 2. ʣ���ַ�С�� 2k �����ڻ���� k ������תǰ k ���ַ�
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k );   // Ҳ��forѭ��ʵ��
            } else {
                // 3. ʣ���ַ����� k ������ʣ���ַ�ȫ����ת��
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