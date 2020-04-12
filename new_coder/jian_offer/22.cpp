#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        bool possible=false;
        int len=pushV.size();
        if(len<=0|| pushV.size()!=popV.size()){
            return false;
        }
        stack<int> s;
        int Ipos=0,Opos=0;
        while(Opos<len){
            while(s.empty()|| s.top()!=popV[Opos]){
                if(Ipos==len) break;
                s.push(pushV[Ipos++]);
            }

            if(s.top()!=popV[Opos]){
                break;
            }
            s.pop();    
            Opos++;
        }
        if(s.empty() && Opos==len){
            possible=true;
        }
        return possible;   
    }
};



int main(){
    vector<int> i,o;
    // vector<int> i={1,2,3,4,5},o={5,4,3,2,1};
    Solution s;
    cout << s.IsPopOrder(i,o) <<endl;



    return 0;
}