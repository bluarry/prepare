#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;


class Solution {
public:
    int slen;
    int longestValidParentheses(string s) {
        slen=s.length();
        if(slen<=1){
            return 0;
        }
        int left=0,right=0,maxlen=0;
        //从左向右扫描
        for(int i=0;i<slen;i++){
            if(s[i]=='('){
                left++;
            }else{
                right++;
            }
            if(left==right){
                maxlen=max(maxlen,2*right);
            }else if(right>left){
                left=right=0;
            }
        }
        left=0,right=0;
        for(int i=slen-1;i>=0;i--){
            if(s[i]=='('){
                left++;
            }else{
                right++;
            }
            if(left==right){
                maxlen=max(maxlen,2*right);
            }else if(right<left){
                left=right=0;
            }
        }
        return maxlen;
    }
};

class Solution3 {
public:
    int slen;
    int longestValidParentheses(string s) {
        slen=s.length();
        stack<int> st;
        if(slen<=1){
            return 0;
        }
        int maxlen=0;
        st.push(-1);
        for(int i=0;i<slen;i++){
            if(s[i]=='('){
                st.push(i);
            }else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    maxlen=max(maxlen,i-st.top());
                }
            }
        }
        return maxlen;
    }
};


class Solution2 {
public:
    int slen;
    int longestValidParentheses(string s) {
        slen=s.length();
        if(slen<=1){
            return 0;
        }
        //cout << slen<<endl;
        int dp[slen]={0};
        int maxlen=0;
        for(int i=1;i<slen;i++){
            if(s[i]==')'){
                if(s[i-1]=='('){
                    dp[i]=(i>=2?dp[i-2]:0)+2;
                }else if(i-dp[i-1]>0 && s[i-dp[i-1]-1]=='('){
                    dp[i]=dp[i-1]+((i-dp[i-1])>=2?dp[i-dp[i-1]-2]:0)+2;
                }
                maxlen=max(maxlen,dp[i]);
            }
        }
        return maxlen;
    }
};



//直观想法是，暴力枚举，时间超限
class Solution1 {
public:
    int slen;
    bool ismatch(string s){
        stack<char> st;
        for(int i=0;i<(int)s.length();i++){
            if(s[i]=='('){
                st.push('(');
            }else if(!st.empty()&&s[i]==')'&&st.top()=='('){
                st.pop();
            }else{
                return false;
            }
        }
        return st.empty();
    }
    int longestValidParentheses(string s) {
        slen=s.length();
        //cout << slen<<endl;
        int maxlen=0;
        for(int i=0;i<slen;i++){
            for(int j=2;j<=slen-i;j+=2){
                //cout << s.substr(i,j) <<endl;
                if(ismatch(s.substr(i,j))){
                    maxlen=max(maxlen,j);
                }
            }
        }
        return maxlen;
    }
};

int main(){
    string x="(()()";    
    Solution s;
    cout << s.longestValidParentheses(x)<<endl;
    return 0;
}