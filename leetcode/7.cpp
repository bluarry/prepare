#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>


using namespace std;



class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        
        vector<string> v(numRows);
        int cur=0;
        bool f=false; //标记是否是边界
        for(char c: s){
            v[cur]+=c;
            if(0==cur||numRows-1==cur) f=!f;
            cur+=f?1:-1;
        }
        string ans;
        for(string a:v) ans+=a;
        return ans;
    }
};

int main(){
    string s="LEETCODEISHIRING";
    Solution ss;
    cout << ss.convert(s,3)<<endl;

    return 0;
}
