#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int minn=INT32_MAX,maxbibifit=0;
        int len=prices.size();
        for(int i=0;i<len;i++){
            if(prices[i]<minn){
                minn=prices[i];
            }else if(prices[i]-minn>maxbibifit){
                maxbibifit=prices[i]-minn;
            }
        }


        return maxbibifit;
    }
};
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        if(len<=1){
            return 0;
        }
        vector<int> d(len);
        for(int i=0;i<len-1;i++){
            d[i]=prices[i+1]-prices[i];
        }
        //求数组d的前i项最大子数组和
        vector<int> dp(len-1,0);
        dp[0]=max(0,d[0]);
        int maxbinifit=dp[0];
        for(int i=1;i<len-1;i++){
            dp[i]=max(0,dp[i-1]+d[i]);
            maxbinifit=max(dp[i],maxbinifit);
        }
        return maxbinifit;
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        int l=0;
        int maxbinifit=0;
        for(int i=0;i<len-1;i++){
            l=max(0,l+prices[i+1]-prices[i]);
            maxbinifit=max(l,maxbinifit);
        }
        return maxbinifit;
    }
};
int main(){
    Solution s;
    vector<int> v={7,1,5,3,6,4};
    cout << s.maxProfit(v)<<endl;
    return 0;
}