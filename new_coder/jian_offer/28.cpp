#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> v;
        v.clear();
        if(str.size()>0)
            helper(str,v,0);
        sort(v.begin(),v.end());
        return v;
    }
    bool can(string s,int start,int end){
        //cout << s<<" " <<start << "  " << end <<endl;
       for(int i=start;i<end;i++){
           if(s[i]==s[end]) return false;
       }
       return true;
    }
    void helper(string s,vector<string> &v,int cur){
        int len=s.size();
        if(cur==len){
            v.push_back(s);
        }else{
            for(int i=cur;i<len;i++){ 
                if(can(s,cur,i)){
                    swap(s[i],s[cur]);
                    helper(s,v,cur+1);
                    swap(s[i],s[cur]);
                }
            }
        }
    }
};
int main(){
    string ss="abc";

    Solution s;
    vector<string> v=s.Permutation(ss);

    for(string a: v)
        cout <<a <<endl;


    return 0;
}