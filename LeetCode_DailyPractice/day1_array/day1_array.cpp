// leetcode 704
#include <iostream>
using namespace std;

class Solution {
public:
    int binary_search(int *nums,int n,int target) {
       if(nums == NULL || n == 0){               // 避免空数组
        return -2;
       } 
       int left = 0, right = n - 1;             // sizeof会求取整个内存长度
       int mid = 0;
       while(left <= right){                     // 若是闭区间[left,right]：left<=right,若是开区间[left,right)left<right
           mid = (right - left) / 2 + left;      // mid这样计算是为了避免数组元素过多时溢出
           if(nums[mid] == target){              // 将截止条件提到前面对部分测试而言可以减少计算时间
               return mid;
           }else if(nums[mid] < target){         
               left = mid + 1;
           }else{
               right = mid - 1;                   // 若是开区间：right = mid
           }
       }
       return -1;
    }

    int search(int *nums, int n, int left, int right, int target){     // 递归法
        if(nums == NULL || n == 0){                                    // 排除空数组
        return -2;
        }
        
        int mid = left + (right - left) / 2;

        if(left > right){                      // 截止条件：没有找到target
            return -1;
        }

        if(nums[mid] == target){               // 截止条件：已经找到target
            return mid;
        }

        while(left <= right){
            if(nums[mid] > target){
                return search(nums, mid - left, left, mid - 1, target);   // 注意是return
            }else{
                return search(nums, right - mid, mid + 1, right, target);
            }
        }
    }
};

int main(){
    int target;
    int n;
    int nums[1000];

    cout << "请输入数组长度：" << endl;
    cin >> n;
    cout<<"请输入目标值："<<endl;
    cin >> target;
    cout << "请输入待查找元素：" << endl;
    for(int i = 0;i < n;++i){
        cin >> nums[i];
    }

    int left = 0, right = n - 1;
    // cout << sizeof(nums) << endl;

    Solution s;
    cout << "相应位置：" << s.binary_search(nums, n, target) << endl;
    cout << "相应位置（递归）" << s.search(nums, n, left, right, target) << endl;
    return 0;
}