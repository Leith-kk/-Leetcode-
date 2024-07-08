// leetcode 704
#include <iostream>
using namespace std;

class Solution {
public:
    int binary_search(int *nums,int n,int target) {
       if(nums == NULL || n == 0){               // ���������
        return -2;
       } 
       int left = 0, right = n - 1;             // sizeof����ȡ�����ڴ泤��
       int mid = 0;
       while(left <= right){                     // ���Ǳ�����[left,right]��left<=right,���ǿ�����[left,right)left<right
           mid = (right - left) / 2 + left;      // mid����������Ϊ�˱�������Ԫ�ع���ʱ���
           if(nums[mid] == target){              // ����ֹ�����ᵽǰ��Բ��ֲ��Զ��Կ��Լ��ټ���ʱ��
               return mid;
           }else if(nums[mid] < target){         
               left = mid + 1;
           }else{
               right = mid - 1;                   // ���ǿ����䣺right = mid
           }
       }
       return -1;
    }

    int search(int *nums, int n, int left, int right, int target){     // �ݹ鷨
        if(nums == NULL || n == 0){                                    // �ų�������
        return -2;
        }
        
        int mid = left + (right - left) / 2;

        if(left > right){                      // ��ֹ������û���ҵ�target
            return -1;
        }

        if(nums[mid] == target){               // ��ֹ�������Ѿ��ҵ�target
            return mid;
        }

        while(left <= right){
            if(nums[mid] > target){
                return search(nums, mid - left, left, mid - 1, target);   // ע����return
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

    cout << "���������鳤�ȣ�" << endl;
    cin >> n;
    cout<<"������Ŀ��ֵ��"<<endl;
    cin >> target;
    cout << "�����������Ԫ�أ�" << endl;
    for(int i = 0;i < n;++i){
        cin >> nums[i];
    }

    int left = 0, right = n - 1;
    // cout << sizeof(nums) << endl;

    Solution s;
    cout << "��Ӧλ�ã�" << s.binary_search(nums, n, target) << endl;
    cout << "��Ӧλ�ã��ݹ飩" << s.search(nums, n, left, right, target) << endl;
    return 0;
}