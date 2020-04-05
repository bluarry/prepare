#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>

using namespace std;
typedef long long ll;

class Solution {
public:
    int uniquePaths(int m, int n) {
        //dp动态规划来做
        vector<int> c(n,1);
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                c[j]+=c[j-1];
            }
        }
        return c[n-1];
    }
};


class Solution2 {
public:
    int uniquePaths(int m, int n) {
        //dp动态规划来做
        int dp[m][n];
        for(int i=0;i<m;i++){
            dp[i][0]=1;
        }
        for(int i=0;i<n;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};


//该方法为排列组合，C++中无大数类，故而，该方法无效
class Solution1 {
public:
    int uniquePaths(int m, int n) {
    	// if(m<=1&&n<=1) return 0;
    	// cout << C(m+n-2,n-1)<<endl;
        // return C(m+n-2,n-1).toInt();
    }
};


int main(){
    Solution s;
    cout << s.uniquePaths(7,3)<<endl;



    return 0;
}
