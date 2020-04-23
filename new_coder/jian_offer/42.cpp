#include <bits/stdc++.h>

using namespace std;

class Solution_1 {
public:
    string ReverseSentence(string str) {/*"she what want you am a student."*/
        int len=str.length();
        if(len<=0) return "";
        reverse(str.begin(),str.end());
        int begin=0,end=0;
        while(begin<=len-1){
            cout << begin << " "<< end << " " << str[begin] <<" "<< str[end]<<endl;
            if(str[begin]==' '){
                begin++;
                end++;
            }else if(str[end]==' '||end==len-1){
                if(end==len-1){
                     reverse(str.begin()+begin,str.end());
                     break;
                }
                reverse(str.begin()+begin,str.begin()+end);
                begin = end;
                
            }else{
                end++;
            }
        }
        return str;
    }
};

class Solution {
public:
    string LeftRotateString(string str, int n) {
        int len=str.length();
        if(len==0|| n<0||n>len) return "";
        if(n==0||n==len) return str;

        reverse(str.begin(),str.begin()+n);
        reverse(str.begin()+n,str.end());
        reverse(str.begin(),str.end());
        return str;
    }
};
int main(){
    Solution s;
    string str="she what want you am a student.";
    cout<< s.LeftRotateString(str,31)<<endl;



    return 0;
}