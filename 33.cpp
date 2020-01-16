#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>


using namespace std;
class Solution {
public:
    int slen;
    int plen;
    vector<vector<bool> > dp;

    bool isMatch(string s, string p) {
        slen=s.length();plen=p.length();
		dp=vector<vector<bool> >(slen+1,vector<bool>(plen+1,false));
		dp[slen][plen]=true;
		for(int i=plen-1;i>=0 && p[i]=='*';i--){
            dp[slen][i]=true;
        }
        
        for(int i=slen-1;i>=0;i--){
            for(int j=plen-1;j>=0;j--){
                bool first_match=(!s.empty() &&
                            (s[i]==p[j]||p[j]=='?'));
                if('*'==p[j] ){
                    //ans= isMatch(s,p.substr(1))|| s.length()>=1 && isMatch(s.substr(1),p);
                    //ans= j<plen && doit(i,j+1,s,p) || i<slen && doit(i+1,j,s,p);
                    dp[i][j]=dp[i][j+1] || dp[i+1][j];
                }else{
                    //return first_match && s.length()>=1 && p.length()>=1&&isMatch(s.substr(1),p.substr(1));
                    dp[i][j] = first_match && dp[i+1][j+1];
                }
            }
        }
        // for(int i=0;i<=slen;i++){
        //     for(int j=0;j<=plen;j++){
        //         cout << dp[i][j] <<" ";
        //     }
        //     cout <<endl;
        // }
        return dp[0][0];     
    }
  
};
class Solution2 {
    //险过
public:
    int slen;
    int plen;
    vector<vector<int> > dp;

    bool isMatch(string s, string p) {
        slen=s.length();plen=p.length();
        dp=vector<vector<int> >(slen+1,vector<int>(plen+1,-1));
        return doit(0,0,s,p);
    }
    bool doit(int i,int j,string s,string p){
        if(-1!=dp[i][j]){
            return 1==dp[i][j];
        }
        bool ans;
        if(j==plen){
            ans=i==slen;
        }else{
            bool first_match=(!s.empty() &&
                            (s[i]==p[j]||p[j]=='?'));
            if('*'==p[j] ){
                //ans= isMatch(s,p.substr(1))|| s.length()>=1 && isMatch(s.substr(1),p);
                ans= j<plen && doit(i,j+1,s,p) || i<slen && doit(i+1,j,s,p);
            }else{
                //return first_match && s.length()>=1 && p.length()>=1&&isMatch(s.substr(1),p.substr(1));
                ans = first_match && i<slen && j<plen && doit(i+1,j+1,s,p);
            }
        }
        dp[i][j]=ans?1:0;
      
        return ans; 
    }
};

class Solution1 {
    //字符串太长，时间超限
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        bool first_match=(!s.empty() &&
                            (s[0]==p[0]||p[0]=='?'));
        if('*'==p[0] && p.length()>=1){
            return isMatch(s,p.substr(1))|| s.length()>=1 && isMatch(s.substr(1),p);
        }else{
            return first_match && s.length()>=1 && p.length()>=1&&isMatch(s.substr(1),p.substr(1));
        }
    }
};

int main(){
    string s="adceb";
    string p="*a*b";
    Solution ss;
    cout << ss.isMatch(s,p) <<endl;
    return 0;
}
