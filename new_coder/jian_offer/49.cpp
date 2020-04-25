#include <bits/stdc++.h>
using namespace std;

class Solution_no1 {
public:
    int syb; //1为+数，0为-数
    std::string& trim(std::string &s)   
    {  
        if (s.empty())   
        {  
            return s;  
        }  
        s.erase(0,s.find_first_not_of(" "));  
        s.erase(s.find_last_not_of(" ") + 1);  
        return s;  
    }  
    bool isnum(char c){
        if(c>='0'&&c<='9') return true;
        return false;
    }
    bool allnum(string s){
        int len=s.size();
        for(int i=0;i<len;i++){
            if(i==0 && (s[0]=='+'||s[0]=='-')) continue;
            if(!isnum(s[i])){
                return false;
            }
        }
        return true;
    }
    int StrToInt(string str) {
        syb=1;
        str=trim(str);
        int len=str.size();
        if(len==0|| !allnum(str))return 0;
        int index=0,ans=0;
        if(str[index]=='-'){
            index++;
            syb=0;
        }else if(str[index]=='+'){
            index++;
        }
        while(index<len){
            if(ans<INT_MAX/10){
                ans*=10;
                ans+=(str[index++]-'0');
            }else if(ans==INT_MAX/10){
                if(syb==1&&(str[index]-'0')<=(INT_MAX%10)){
                    ans*=10;
                    ans+=(str[index++]-'0');
                }else if(syb==1){
                    ans=INT_MAX;
                    break;
                }else if(syb==0 &&(str[index]-'0')<= -(INT_MIN%10) ){
                    ans*=10;
                    ans+=(str[index++]-'0');
                }else if(syb==0){
                    ans=INT_MIN;
                    break;
                }
            }else{
                ans= syb==1?INT_MAX:INT_MIN;
                break;
            }

        }
        if(syb==0&& ans>0){
            ans=-ans;
        }
        return ans;
    }
};
class Solution_newcode {
public:
    int syb; //1为+数，0为-数
    std::string& trim(std::string &s)   
    {  
        if (s.empty())   
        {  
            return s;  
        }  
        s.erase(0,s.find_first_not_of(" "));  
        s.erase(s.find_last_not_of(" ") + 1);  
        return s;  
    }  
    bool isnum(char c){
        if(c>='0'&&c<='9') return true;
        return false;
    }
    bool allnum(string s){
        int len=s.size();
        for(int i=0;i<len;i++){
            if(i==0 && (s[0]=='+'||s[0]=='-')) continue;
            if(!isnum(s[i])){
                return false;
            }
        }
        return true;
    }
    int StrToInt(string str) {
        syb=1;
        str=trim(str);
        int len=str.size();
        if(len==0|| !allnum(str))return 0;
        int index=0,ans=0;
        if(str[index]=='-'){
            index++;
            syb=0;
        }else if(str[index]=='+'){
            index++;
        }
        while(index<len){
            if(ans<INT_MAX/10){
                ans*=10;
                ans+=(str[index++]-'0');
            }else if(ans==INT_MAX/10){
                if(syb==1&&(str[index]-'0')<=(INT_MAX%10)){
                    ans*=10;
                    ans+=(str[index++]-'0');
                }else if(syb==1){
                    ans=0;
                    break;
                }else if(syb==0 &&(str[index]-'0')<= -(INT_MIN%10) ){
                    ans*=10;
                    ans+=(str[index++]-'0');
                }else if(syb==0){
                    ans=0;
                    break;
                }
            }else{
                ans= 0;
                break;
            }

        }
        if(syb==0&& ans>0){
            ans=-ans;
        }
        return ans;
    }
};
int main(){
    freopen("in.txt","r",stdin);
    string s;
    Solution so;
    while(cin >> s){
        cout << so.StrToInt(s)<<endl;
    }



    return 0;
}