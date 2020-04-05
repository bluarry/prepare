#include <iostream>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dpi10=0,dpi11=INT32_MIN,dpi20=0,dpi21=INT32_MIN;
        
        //  dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i]);
        // dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i]);
        for(int p:prices){
            dpi20=max(dpi20,dpi21+p);
            dpi21=max(dpi21,dpi10-p);
            dpi10=max(dpi10,dpi11+p);
            dpi11=max(dpi11,-p);
        }
        return dpi20;
    }
};
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int a=0,b=INT32_MIN,c=0,d=INT32_MIN;
        
        //  dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i]);
        // dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i]);
        for(int p:prices){
            c=max(c,d+p);
            d=max(d,a-p);
            a=max(a,b+p);
            b=max(b,-p);
        }
        return c;
    }
};
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
         if(len<=1){
            return 0;
        }
        int dp[len+1][3][2];
        memset(dp,0,sizeof(dp));

        for(int i=0;i<len;i++){
            for(int k=2;k>=1;k--){
                if(-1==i-1){
                    dp[i][k][0]=0;
                    dp[i][k][1]=-prices[i];
                    continue;
                }
                dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i]);
                dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i]);
            }
        }
        return dp[len-1][2][0];
    }
};

int main(){
    Solution s;
    vector<int> v={3,3,5,0,0,3,1,4};
    cout << s.maxProfit(v)<<endl;
    return 0;
}