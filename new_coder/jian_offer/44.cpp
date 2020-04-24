#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        int len=numbers.size();
        if(len==0) return false;
        
        sort(numbers.begin(),numbers.end());
        int numzero=0;
        int i=0;
        for(i=0;i<len&&numbers[i]==0;i++) numzero++;
        int numcha=0;
        for(;i<len-1;i++){
            if(numbers[i+1]==numbers[i]) return false;
            numcha+=(numbers[i+1]-numbers[i]-1);
        }
        // cout << numzero << " " << numcha <<endl;
        return numcha <= numzero;
    }
};

int main(){

    vector<int> v={1,0,0,1,0};
    Solution s;
    cout << s.IsContinuous(v) <<endl;

    return 0;
}