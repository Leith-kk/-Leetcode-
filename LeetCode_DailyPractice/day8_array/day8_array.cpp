// leetcode 209 ��̬���ڷ�
#include <iostream>
#include <vector>

// ���ⷨ�Ĺؼ������������ⷨ��˼ά�����ȹ̶�����ָ���λ�ã�����sum>=target����������ƶ���ʼָ�루���Ƿ�����sum>=target�����ҵ��������ϵ���С����
using namespace std;
class Solution{
public:
    int minSubArrayLen(int target, vector<int>nums){
        int result = INT32_MAX;                                   // ��������ĳ���Ҫȡ��С������Ҫ��ȡ���Ƚϣ�����ȥ��С     
        int subLenth = 0;                                         // ��¼��ǰ�ַ��Ӵ��ĳ���
        int sum = 0;                                              // ��¼��͵�ֵ
        int start = 0;                                            // ��¼�Ӵ�����ʼλ��
        for(int end = 0; end < nums.size();++end){                // ��¼�Ӵ�����ֹλ��
            sum += nums[end];                      
            while(sum >= target){                                 // �ҵ�������Ҫ����Ӵ�
               subLenth = end - start + 1;                         
               result = result < subLenth ? result : subLenth;    // �Ƚϵ�ǰ�Ӵ�����һ�μ�¼���Ӵ�˭����
               sum -= nums[start ++];                             // ����ƶ���ʼλ�ã�����ǰ�Ӵ��ܷ�������
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};