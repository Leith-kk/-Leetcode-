// leetcode 844
#include <iostream>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.length() - 1, j = T.length() - 1;        // �Ӻ���ǰ����
        int skipS = 0, skipT = 0;                          // ��¼����'#'�Ĵ���

        while (i >= 0 || j >= 0) {
            // �����ַ���s
            while (i >= 0) {
                if (S[i] == '#') {
                    skipS++, i--;               // ��ǰ�ַ�Ϊ'#'��skipS++����ʾ��һ��Ҫ�������ַ�
                } else if (skipS > 0) {         // ��ǰ�ַ���Ϊ'#'�������������Ҫô������Ҫô�������ַ���t���Ա�
                    skipS--, i--;               // ���1��skipS > 0�����ַ�����
                } else {
                    break;                      // ���2��skipS = 0�����ַ��������ַ���t�Ƚϣ�����Сѭ������ȽϵĴ�ѭ��
                }
            }

            // ���ַ���Tִ�����ַ���S��ͬ�Ĳ���
            while (j >= 0) {
                if (T[j] == '#') {
                    skipT++, j--;
                } else if (skipT > 0) {
                    skipT--, j--;
                } else {
                    break;
                }
            }

            // �Ƚ����������ַ�������û�б������ķ�'#'�ַ�
            if (i >= 0 && j >= 0) {           // �ַ���S��T��û�н�ֹʱ����Աȣ�����ֹ��˵���Ѿ�������+�Աȣ������ˣ�����true������
                if (S[i] != T[j]) {           // �����ֱ��false��������ֹ
                    return false;
                }
            } else {                          // ��һ���ַ����Ѿ���ֹ������һ���ַ�����δ��ֹ������Ҫ�ٱȽϣ��϶������
                if (i >= 0 || j >= 0) {
                    return false;
                }
            }

            // һ�αȽϽ�������ȥ����ǰ����ַ�
            i--, j--;
        }
        return true;
    }
};