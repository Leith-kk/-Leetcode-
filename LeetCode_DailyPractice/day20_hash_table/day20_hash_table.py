# д��һ
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        record = [0] * 26
        for i in s:
            #������Ҫ��ס�ַ�a��ASCII��ֻҪ���һ�������ֵ�Ϳ�����
            record[ord(i) - ord("a")] += 1
        for i in t:
            record[ord(i) - ord("a")] -= 1
        for i in range(26):
            if record[i] != 0:
                #record��������е�Ԫ�ز�Ϊ��0��˵���ַ���s��t һ����˭�����ַ�����˭�����ַ���
                return False
        return True
    
# д����
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        from collections import defaultdict
        
        s_dict = defaultdict(int)
        t_dict = defaultdict(int)
        for x in s:
            s_dict[x] += 1
        
        for x in t:
            t_dict[x] += 1
        return s_dict == t_dict

# д����
class Solution(object):
    def isAnagram(self, s: str, t: str) -> bool:
        from collections import Counter
        a_count = Counter(s)
        b_count = Counter(t)
        return a_count == b_count