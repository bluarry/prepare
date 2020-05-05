#include <bits/stdc++.h>

using namespace std;
/*

请实现一个函数用来匹配包括'.'和'*'的正则表达式。
模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。
在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
*/
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        //结尾了 true
        if(str[0]=='\0' && pattern[0]=='\0'){
            return true;
        }
        if(pattern[0]!='\0'&& pattern[1]=='*'){ //忽略*前面的字符
            if(match(str,pattern+2)){
                return true;
            }
        }
        if((pattern[0]=='.'&& str[0]!='\0') || str[0]==pattern[0]){
            if(match(str+1,pattern+1)) return true;
            if(pattern[1]=='*'&& match(str+1,pattern)) return true;
        }
        return false;
    }
};
int main(){
    freopen("in.txt","r",stdin);
    Solution s;
    string str1,str2;
    while(cin >> str1>>str2){
        cout <<str1 <<" " << str2<<endl;
        // char* s1=new char[strlen(str1.c_str())+1];
        // strcpy(s1,str1.c_str());
        // char* s2=new char[strlen(str2.c_str())+1];
        // strcpy(s2,str2.c_str());
        cout <<s.match((char *)str1.data(),(char *)str2.data())<<endl;
    }



    return 0;
}