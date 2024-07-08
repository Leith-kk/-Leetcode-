// leetcode 27 ���൱��ʵ��erase���ú�����
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    // ���Ʊ����ⷨ���ȱ����ⷨ��һ��������Ϊ����Ŀ����˳��
    int removeElement(vector<int>& nums, int val) {
        int a[100];                                  // ������¼������val��Ӧ���±�
        int cout = 0;                                // ��������������val���ֵĴ���
        int sub = nums.size();                       // �������ĳ��ȱ���֮�����

        // ��¼������val�����±�
        for(int i = 0; i < nums.size();++i){         
            if(nums[i] == val){
                a[i] = 0;
                ++cout;
            }
            else{
                a[i] = 1;
            }
        }

        // ��nums������ĩβ����val������ǰ���val�Ŀ�λ������=ɾȥ����˫ָ����ζ�ˣ���һ�ľ���˫ָ�룩
        for(int i = 0;i < nums.size();++i){
            if(nums[i] == val){
                for(int j = sub - 1;j >= 0;--j){       // �˴���sub�����ܹؼ�
                    if(a[j] == 1){
                        nums[i] = nums[j];
                        sub = j;
                        break;
                    }
                }
            }
        }
        return nums.size() - cout;
    }

    // �ص㣺˫ָ�뷨����������������
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int left = 0;                                  // ��ָ���ƶ�����Ϊ����ֵ��Ԫ��
        for (int right = 0; right < n; right++) {      // rightָ���ƶ��죬Ϊ���ڴ����Ԫ��
            if (nums[right] != val) {
                nums[left] = nums[right];              // rightָ��Ԫ��Ϊval��right�ͺ���һλ������һ��Ԫ�أ�rightָ���valԪ�أ��Ͱ�����ֵ��left
                left++;
            }
        }
        return left;
    }  

    // ��Դ����˫ָ���Ż���������һ������
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = nums.size() - 1;              // left���ף�right��β 
        while (left < right) {
            if (nums[left] == val) {
                nums[left] = nums[right];
                right--;                                    // left��right���м��ƶ�
            } else {
                left++;
            }
        }
        return left;
    }
};