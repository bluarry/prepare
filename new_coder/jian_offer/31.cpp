#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray1(vector<int> array) {
        int len=array.size();
        if(len==0) return 0;
        int nsum=0,fsum=INT32_MIN;
        for(int i=0;i<len;i++){
            if(nsum<0){
                nsum=array[i];
            }else{
                nsum+=array[i];
            }
            if(nsum>fsum){
                fsum=nsum;
            }
        }
        return fsum;
    }
    int FindGreatestSumOfSubArray(vector<int> array) {
        //1,-2,3,10,-4,7,2,-5
        int len=array.size();
        if(len==0) return 0;
        vector<int> dp(len,0);
        dp[0]=array[0];
        int maxx=INT32_MIN;
        for(int i=1;i<len;i++){
            if(dp[i-1]<=0) dp[i]=array[i];
            else{
                dp[i]=dp[i-1]+array[i];
            }
            maxx=max(dp[i],maxx);
        }
       
        return maxx;
    }
};
int main(){
    vector<int> v={-2,-8,-1,-5,-9};
    Solution s;
    cout << s.FindGreatestSumOfSubArray(v) <<endl;



    return 0;
}