#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        vector<int> v('z'-'A'+5,0);
        for(int i=0;i<str.size();i++){
            v[str[i]-'A']++;
        }
        int ans=-1;
        for(int i=0;i<str.size();i++){
            if(v[str[i]-'A']==1){
                //ans=str[i];
                ans=i;
                break;
            }
        }
        return ans;
    }
};
int main(){
    string str;
    Solution s;
    while(cin >>str){
        cout <<(char)s.FirstNotRepeatingChar(str)<<endl;
    }



    return 0;
}