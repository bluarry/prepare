#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int c:coins){
                    if(c <=i){
                        dp[i]=min(dp[i],dp[i-c]+1);
                    }
            }
        }
        return  dp[amount]==amount+1?-1:dp[amount];
    }

    int coinChange1(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins)
                if (coin <= i)
                    dp[i] = min(dp[i], dp[i - coin] + 1);
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
    
};


int main(){
    Solution s;
    vector<int> c={1,2,5};
    cout << s.coinChange(c,11)<<endl;

    return 0;
}




