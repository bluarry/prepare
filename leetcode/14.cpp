#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;
//分治算法,待补



class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        if(strs.size()==1) return strs[0]; 
        int index=0,flag=1;
        string ans="",b=strs[0];
        while(flag){
            for(auto s:strs){
                if(index>=s.length()){
                    flag=0;break;
                }else if(index>=b.length()){
                    flag=0;break;
                }else if(s[index]!=b[index]){
                    flag=0;break;
                }
            }
            if(flag){index++;}
            else break;
        }
        return b.substr(0,index);
    }
};

int main(){
    vector<string> strs={"flower","fllow","floooo"};    
    Solution s;
    cout << s.longestCommonPrefix(strs) <<endl;


    return 0;
}
