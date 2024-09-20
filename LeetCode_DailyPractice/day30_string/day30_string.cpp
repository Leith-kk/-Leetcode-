// KamaCode 54
#include <iostream>
#include <string>

using namespace std;

int main() {
    string str = "a5b";
    int count = 0;
    // cin >> str;

    // 统计字符串中数字的个数
    for(int i = 0; i < str.size(); ++i){
        if(str[i] >= '0' && str[i] <= '9') count++;
    }

    int oldIndex = str.size() - 1;  // 记录原数组的最后一位所在位置
    // 对原数组进行扩展，number原本替换的位置已经有一个字符位，所以此处是5
    str.resize(str.size() + count * 5);
    int newIndex = str.size() - 1;  // 记录新数组的最后一位所在位置
    // 使用双指针法重新排列数组
    for(int i = oldIndex; i >= 0; --i){
        //while(newIndex >= 0){
            if(str[i] >= '0' && str[i] <= '9'){
                str[newIndex--] = 'r';
                str[newIndex--] = 'e';
                str[newIndex--] = 'b';
                str[newIndex--] = 'm';
                str[newIndex--] = 'u';
                str[newIndex--] = 'n';
            }
            else str[newIndex--] = str[i];
        
    }
    
    cout << str << endl;
    return 0;
}
