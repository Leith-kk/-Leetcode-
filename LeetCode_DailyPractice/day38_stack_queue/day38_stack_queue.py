class Solution:
    def removeDuplicates(self, s) -> str:
        res = list()
        for item in s:
            if res and res[-1] == item:
                res.pop()
            else:
                res.append(item)

        return "".join(res)

if __name__ == "__main__":
    s = "abbaca"
    test = Solution()
    print(test.removeDuplicates(s))