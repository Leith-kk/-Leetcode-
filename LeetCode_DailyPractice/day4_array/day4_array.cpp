// leetcode 69
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    // �������ַ���������
    int mySqrt(int x) {
        if(x == 0){
            return 0;
        }
        
        long long int a[100000];              // �����洢����������
        int left = 0, right = 0, mid = 0;
        string str = to_string(x);  
        int  k = str.size();        // ����x��λ��

        if(k % 2 == 0){             // nλ����ƽ���Ľ�����λ��Ҳ����n/2λ
            k = k / 2;
        }else{
            k = k / 2 + 1;
        }

        int c = 1;
        for(int i = 0;i < k;++i){    // �����д浽1e+(n/2)������
            c*= 10;
        }

        right = c - 1;               // ����right���±�ܹؼ�

        for(int i = 0;i < c;++i){    // ��������ҵ�������һ��̫���࣬����ֱ��ʹ��1-C��
            a[i] = i + 1;
        }

        while(left <= right){        // ���ֲ���
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

    // ʹ����ѧ��������ָ��������Ϊeָ������
    int calculator_sqrt(int x){
        if (x == 0) {
            return 0;
        }
        int ans = exp(0.5 * log(x));
        return ((long long)(ans + 1) * (ans + 1) <= x ? ans + 1 : ans);
    }

    // ������ַ�����򵥶���
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

    // ţ�ٵ�������f(x) = x^2 - C����㣬�����������ٶȱȶ��ַ�����
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
            x0 = xi;           // x0ÿ�ζ������
        }
        return int(x0);
    }
};

int main(){
    int x;
    cout << "������x��ֵ��" << endl;
    cin >> x;
    Solution t;
    cout << t.mySqrt(x) << endl;
    return 0;
}
