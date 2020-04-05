#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0,target=0,len=nums.size();
        for(vector<int>::iterator it=nums.begin();it!=nums.end();it++){
            sum +=*it;
        }
        if(sum&1){
            return false;
        }
        target=sum/2;
        bool dp[len][target+1];
        memset(dp,0,sizeof(dp));

        for(int i=0;i<len;i++){
            dp[i][0]=true;
        }
       
        for(int i=0;i<len;i++){
            if(nums[i]<=target){
                dp[i][nums[i]]=true;
            }
        }
       
        for(int i=1;i<len;i++){
            for(int j=1;j<=target;j++){
                dp[i][j]=dp[i-1][j] || (j-nums[i]>=0 && dp[i-1][j-nums[i]]);
            }
        }

        // for(int i=0;i<len;i++)
        //     for(int j=0;j<=target;j++)
        //         j==target?cout << dp[i][j]<<endl:cout << dp[i][j]<<" " ;

        return dp[len-1][target];        
    }
};




int main(){
    vector<int> n={1,2,5};
    Solution s;
    cout << s.canPartition(n)<<endl;

    return 0;
}