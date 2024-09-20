// leetcode 202

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution{
    public:
    // 求数n每位数的平方和
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
        // 使用哈希表记录每次求和的值，下一次在哈希表中查找，如果s在哈希表中，说明继续计算无法为1，直接返回false
        // 若s不在哈希表中，将s添加到哈希表中并进行下一轮计算
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

// 测试
int main(){
    int a = 2;

    Solution test;

    cout << test.isHappy(a) << endl;

    return 0;
}