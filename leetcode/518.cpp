#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
public:
    int change(int amount, vector<int>& coins) {
        int len=coins.size();
        if(0==len) return amount==0?1:0;
        vector<vector<int> > dp(len+1,vector<int>(amount+1,0));
        
        dp[0][0]=1;

        for(int i=coins[0];i<=amount;i+=coins[0]){
            dp[0][i]=1;
        }
        for(int i=1;i<len;i++){
            for(int j=0;j<=amount;j++){
                for(int k=0;k*coins[i]<=j;k++){
                    dp[i][j]+=dp[i-1][j-k*coins[i]];
                }
            }
        }

        // for(int i=0;i<len;i++){
        //     for(int j=0;j<=amount;j++){
        //         j==amount?cout << dp[i][j] << endl:cout << dp[i][j] <<" ";
        //     }
        // }
        return dp[len-1][amount];
    }
};
class Solution2 {
public:
    int change(int amount, vector<int>& coins) {
        int len=coins.size();
        if(0==len) return amount==0?1:0;
        vector<vector<int> > dp(len+1,vector<int>(amount+1,0));
        
        dp[0][0]=1;

        for(int i=coins[0];i<=amount;i+=coins[0]){
            dp[0][i]=1;
        }

        for(int i=1;i<len;i++){
            for(int j=0;j<=amount;j++){
                dp[i][j]= dp[i-1][j];
                if(j-coins[i]>=0)
                 dp[i][j] += dp[i][j-coins[i]] ;
            }
        }
        
        
        // for(int i=0;i<len;i++){
        //     for(int j=0;j<=amount;j++){
        //         j==amount?cout << dp[i][j] << endl:cout << dp[i][j] <<" ";
        //     }
        // }


        return dp[len-1][amount];
    }

};

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int len=coins.size();
        if(0==len) return amount==0?1:0;
        vector<int> dp(amount+1,0);
        
        dp[0]=1;

        for(int i=coins[0];i<=amount;i+=coins[0]){
            dp[i]=1;
        }

        for(int i=1;i<len;i++){
            for(int j=0;j<=amount;j++){
                if(j-coins[i]>=0)
                 dp[j] += dp[j-coins[i]] ;
            }
        }
        
        
        // for(int i=0;i<len;i++){
        //     for(int j=0;j<=amount;j++){
        //         j==amount?cout << dp[i][j] << endl:cout << dp[i][j] <<" ";
        //     }
        // }


        return dp[amount];
    }

};

int main(){
    Solution s;
    vector<int> x={1,2,5};
    cout << s.change(5,x)<<endl;

    return 0;
}