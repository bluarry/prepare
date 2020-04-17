#include <bits/stdc++.h>

using namespace std;
class Solution1 {
public:
    bool isu(int n){
        while(n%2==0)n/=2;
        while(n%3==0)n/=3;
        while(n%5==0)n/=5;
        return n==1;
    }
    int GetUglyNumber_Solution(int index) {
        int ind=0,num=0;
        while(ind<index){
            num++;
            if(isu(num)){
                ind++;
            }
        }
        return num;
    }
};
class Solution {
public:
    vector<int> uglynums;
    int ind=1,pos2=0,pos3=0,pos5=0;
     Solution(){
        uglynums.push_back(1);
     }
    int GetUglyNumber_Solution(int index) {
        
        if((int)uglynums.size() > index) return uglynums[index-1];
        while(ind<index){
            int mmin=min(uglynums[pos2]*2,min(uglynums[pos3]*3,uglynums[pos5]*5));
            uglynums.push_back(mmin);
            while(uglynums[pos2]*2<=uglynums[ind])pos2++;
            while(uglynums[pos3]*3<=uglynums[ind])pos3++;
            while(uglynums[pos5]*5<=uglynums[ind])pos5++;
            ++ind;
        }
        return uglynums[index-1];
    }
};

int main(){

    Solution s;
    int x;
    while(cin >> x){
        cout <<s.GetUglyNumber_Solution(x)<<endl;
    }
    

    return 0;
}