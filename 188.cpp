#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>


using namespace std;
class Solution {
public:
    int mm(vector<int>& prices){
        int len=prices.size();
        int res=0;
        for(int i=0;i<len-1;i++){
            if(prices[i]<prices[i+1]){
                res+=prices[i+1]-prices[i];
            }
        }
        return res;
    }
    int maxProfit(int k, vector<int>& prices) {
        //k -> INF ?
        int len=prices.size();
        if(len<=1){
            return 0;
        }
        if(k>=len/2){
            //贪心
            return mm(prices);
        }
        //有bug，没找出来
        // int dp[len+1][k+1][2];
        vector<vector<int> > dp(k+1,vector<int>(2,0));
        int dpk0=0,dpk1=INT32_MIN,t=0;
        for(int i=0;i<len;i++){            
            for(int kk=k;kk>=1;kk--){
                dpk0=max(dpk0,dpk1+prices[i]);
                dpk1=max(dpk1,t-prices[i]);
                t=dpk0;
                // if(-1==i-1){
                //     dp[kk][0]=0;
                //     dp[kk][1]=-prices[i];
                //     continue;
                // }
                // dp[kk][0]=max(dp[kk][0],dp[kk][1]+prices[i]);
                // dp[kk][1]=max(dp[kk][1],dp[kk-1][0]-prices[i]);
            }
        }
        return dpk0;
    }
};



class Solution2 {
public:
    int mm(vector<int>& prices){
        int len=prices.size();
        int res=0;
        for(int i=0;i<len-1;i++){
            if(prices[i]<prices[i+1]){
                res+=prices[i+1]-prices[i];
            }
        }
        return res;
    }
    int maxProfit(int k, vector<int>& prices) {
        //k -> INF ?
        int len=prices.size();
        if(len<=1){
            return 0;
        }
        if(k>=len/2){
            //贪心
            return mm(prices);
        }

        // int dp[len+1][k+1][2];
        vector<vector<int> > dp(k+1,vector<int>(2,0));
        for(int i=0;i<len;i++){
            for(int kk=k;kk>=1;kk--){
                if(-1==i-1){
                    dp[kk][0]=0;
                    dp[kk][1]=-prices[i];
                    continue;
                }
                dp[kk][0]=max(dp[kk][0],dp[kk][1]+prices[i]);
                dp[kk][1]=max(dp[kk][1],dp[kk-1][0]-prices[i]);
            }
        }
        return dp[k][0];
    }
};
class Solution1 {
public:
    int mm(vector<int>& prices){
        int len=prices.size();
        int res=0;
        for(int i=0;i<len-1;i++){
            if(prices[i]<prices[i+1]){
                res+=prices[i+1]-prices[i];
            }
        }
        return res;
    }
    int maxProfit(int k, vector<int>& prices) {
        int len=prices.size();
        if(len<=1){
            return 0;
        }
        
        if(k>=len/2){
            //贪心
            return mm(prices);
        }
        // int dp[len+1][k+1][2];
        vector<vector<vector<int> > > dp(len+1,vector<vector<int> >(k+1,vector<int>(2,0)));
        for(int i=0;i<len;i++){
            for(int kk=k;kk>=1;kk--){
                if(-1==i-1){
                    dp[i][kk][0]=0;
                    dp[i][kk][1]=-prices[i];
                    continue;
                }
                dp[i][kk][0]=max(dp[i-1][kk][0],dp[i-1][kk][1]+prices[i]);
                dp[i][kk][1]=max(dp[i-1][kk][1],dp[i-1][kk-1][0]-prices[i]);
            }
        }

        return dp[len-1][k][0];
    }
};

int main(){
    Solution s;
    vector<int> v={3,3,5,0,0,3,1,4};
    cout << s.maxProfit(2,v)<<endl;
    return 0;
}