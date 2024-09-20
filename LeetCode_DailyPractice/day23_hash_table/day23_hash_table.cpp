// leetcode 202

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution{
    public:
    // ����nÿλ����ƽ����
    int getSquareSum(int n){
        int Sum;
        int temp;

        while(n > 0){
            temp = n % 10;
            n = n / 10;
            Sum += temp * temp;
        }

        return Sum;
    }

    bool isHappy(int n){
        int s;
        // ʹ�ù�ϣ���¼ÿ����͵�ֵ����һ���ڹ�ϣ���в��ң����s�ڹ�ϣ���У�˵�����������޷�Ϊ1��ֱ�ӷ���false
        // ��s���ڹ�ϣ���У���s��ӵ���ϣ���в�������һ�ּ���
        unordered_set<int> set;
        while(true){
            s = getSquareSum(n);
            if(s == 1) return true;

            if(set.find(s) != set.end()) return false;
            else set.insert(s);

            n = s;
        }
    }
};

// ����
int main(){
    int a = 2;

    Solution test;

    cout << test.isHappy(a) << endl;

    return 0;
}