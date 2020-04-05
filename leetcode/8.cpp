#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>


using namespace std;

class Solution {
public:
    bool isEffect(char c){
        if(c=='-'||c=='+'||(c>='0'&& c<='9')) return true;
        return false;
    }
    bool isnum(char c){
        if(c>='0'&& c<='9') return true;
        return false;
    }
    string trim(string str){
        int index=0;
        while(str[index++]==' ');
        return str.substr(index-1);
    }
    int myAtoi(string str) {
        str=trim(str);
        //cout << str<<endl;
        int flag=0,ans=0,len=str.length(),p=0,n=0;
        if(len==0) return 0;
        
        if(isEffect(str[0])) 
            p=0;
        else
        	return 0;

        if(str[0]=='-') flag=1,p++;
        else if(str[0]=='+') p++;
        //cout << "len= " <<len<<endl;
        for(int i=p;i<len;i++){
            if(isnum(str[i])){
                n=i;
            }else
            {
                break;
            }
            
        }
        //cout << p << " " << n <<endl;
        // 当正数处理
        int flag2=0;
        int c=0;
        for(int i=p;i<=n;i++){
            c=str[i]-'0';
            if( ans > INT32_MAX/10 ||(ans==INT32_MAX/10 && c>7)){
                flag2=1;
                ans=INT32_MAX;
                break;
            }
            ans=ans*10+c;
        }
        if(flag){
            if(flag2) ans=INT32_MIN;
            else ans=-ans;
        }
        return ans;
    }
};
int main(){
    Solution ss;
    string s="-2147483648" ;
    cout << ss.myAtoi(s)<<endl;

    return 0;
}
