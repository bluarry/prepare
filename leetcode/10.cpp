#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<bool> > *dp;
     int slen;
     int plen;
    //回溯法 持久化
    bool isMatch(string s, string p) {
        slen=s.length(),plen=p.length();
        dp=new vector<vector<bool> >(slen+1,vector<bool>(plen+1,false));
        (*dp)[slen][plen]=true;
        for(int i=slen;i>=0;i--){
            for(int j=plen-1;j>=0;j--){    
                bool first_match=(i<slen &&
                                (p[j]==s[i]||p[j]=='.'));
                if(j+1<plen && p[j+1]=='*'){
                    (*dp)[i][j]= (*dp)[i][j+2] ||(first_match && (*dp)[i+1][j]);
                }else{
                    (*dp)[i][j]=first_match && (*dp)[i+1][j+1];
                }
            }
        }
        return (*dp)[0][0];
    }
};



class Solution2 {
public:
    vector<vector<int> > *m;
     int slen;
     int plen;
    //回溯法 持久化
    bool isMatch(string s, string p) {
        slen=s.length(),plen=p.length();
        m=new vector<vector<int> >(slen+1,vector<int>(plen+1,-1));
        // for(int i=0;i<slen;i++)
        // {
        //     for(int j=0;j<plen;j++){
        //         cout << (*m)[i][j] <<" ";
        //     }
        //     cout <<endl;
        // }
        return dp(0,0,s,p);
    }
    bool dp(int i,int j,string s,string p){
        if((*m)[i][j]!=-1){
            return 1==(*m)[i][j];
        }
        bool ans;
        if(j==plen){
            ans=i==slen;
        }else{
            bool first_match=(i<slen && 
                                (s[i]==p[j]||p[j]=='.'));
            if(j+1 <plen && p[j+1]=='*'){
                ans= (first_match && dp(i+1,j,s,p)) || dp(i,j+2,s,p); 
            }else{
                ans= first_match && dp(i+1,j+1,s,p);
            }
        }
        (*m)[i][j]=ans?1:0;
        return ans;
    }
};
class Solutionexp {
public:
    bool isEqual(char s, char p){
        if(s == p || p == '.'){
            return true;
        }else{
            return false;
        }
    }

    bool isMatch(string s, string p) {
        int slen = s.size();
        int plen = p.size();
        bool dp[slen + 1][plen + 1];//加1表示字符为空的情况
        //初始化当s,p其中某一个为空的情况。
        //都为空,当然能匹配上
        dp[0][0] = true;
        //p为空，不能匹配
        for(int i= 1; i <= slen; i++){
           dp[i][0] = false; 
        }

        //s为空，在p的第二个字符为空的情况下是可以匹配成功的
        for(int i= 1; i <= plen; i++){
           if((p[i - 1] == '*') && (dp[0][i - 2])){
            dp[0][i] = true; 
           }else{
            dp[0][i] = false; 
           }
        }

        //引入星号后，dp[i][j]中的i和j在能够匹配的情况下不在需要相等。
        for(int i = 1; i <= slen; i++){
            for(int j = 1; j <=plen; j++){
                //星号可以匹配0次，1次，多次
                if(p[j - 1] == '*'){
                    // abc* 与 ab是能匹配的，所以dp[2][4] = true;
                    // 这种情况下，只需要ab部分相等即可，即dp[i][j - 2] = true时
                    // dp[i][j]=true;

                    // b与c不相等，触发0次匹配
                    if(false == isEqual(s[i - 1], p[j - 2])){
                        dp[i][j] = dp[i][j - 2];    
                    }else{
                    //abc*d 与abc触发一次匹配    dp[i][j] = dp[i][j - 1];
                    //abc*d 与abccccc触发多次匹配dp[i][j] = dp[i - 1][j]
                        if(dp[i][j - 1] || dp[i - 1][j] || dp[i][j -2]){
                            dp[i][j] = true;
                        }else{
                            dp[i][j] = false;
                        }
                    }
                    
                }
                else if(true == isEqual(s[i - 1], p[j - 1])){
                    dp[i][j] = dp[i - 1][j - 1];
                }else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[slen][plen];
    }
};


class Solution1 {
public:
    //回溯法
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        bool first_match=(!s.empty() &&
                            (s[0]==p[0]||p[0]=='.'));
        if(p.length()>=2 && p[1]=='*'){
            return (isMatch(s,p.substr(2))||
                    (first_match && isMatch(s.substr(1),p)));
        }else{
            return first_match && isMatch(s.substr(1),p.substr(1));
        }
    }
};

int main(){
    string s="av",p=".*..";
    Solution so;
    cout << so.isMatch(s,p)<<endl;
    return 0;
}