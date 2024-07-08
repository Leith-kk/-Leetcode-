// leetcode 69
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    // 暴力二分法（最慢）
    int mySqrt(int x) {
        if(x == 0){
            return 0;
        }
        
        long long int a[100000];              // 用来存储待处理数组
        int left = 0, right = 0, mid = 0;
        string str = to_string(x);  
        int  k = str.size();        // 计算x的位数

        if(k % 2 == 0){             // n位数开平方的结果最高位数也就是n/2位
            k = k / 2;
        }else{
            k = k / 2 + 1;
        }

        int c = 1;
        for(int i = 0;i < k;++i){    // 数组中存到1e+(n/2)个数字
            c*= 10;
        }

        right = c - 1;               // 定义right的下标很关键

        for(int i = 0;i < c;++i){    // 存入待查找的数（这一步太多余，不如直接使用1-C）
            a[i] = i + 1;
        }

        while(left <= right){        // 二分查找
            mid = left + (right - left) / 2;
            if((a[mid] * a[mid]  == x )||(a[mid] * a[mid] < x && a[mid+1] * a[mid+1] > x )){
                return a[mid];
            }else if(a[mid] * a[mid] > x){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        
        return 0;
    }

    // 使用数学函数，将指数函数化为e指数函数
    int calculator_sqrt(int x){
        if (x == 0) {
            return 0;
        }
        int ans = exp(0.5 * log(x));
        return ((long long)(ans + 1) * (ans + 1) <= x ? ans + 1 : ans);
    }

    // 这个二分法代码简单多了
    int mySqrt(int x) {
        int l = 0, r = x, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }

    // 牛顿迭代法求f(x) = x^2 - C的零点，二阶收敛，速度比二分法更快
    int Newton_Sqrt(int x) {
        if (x == 0) {
            return 0;
        }

        double C = x, x0 = x;
        while (true) {
            double xi = 0.5 * (x0 + C / x0);
            if (fabs(x0 - xi) < 1e-7) {
                break;
            }
            x0 = xi;           // x0每次都会更新
        }
        return int(x0);
    }
};

int main(){
    int x;
    cout << "请输入x的值：" << endl;
    cin >> x;
    Solution t;
    cout << t.mySqrt(x) << endl;
    return 0;
}
