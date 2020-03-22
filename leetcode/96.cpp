#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;


class Solution1 {
public:
    int numTrees(int n) {
        long long C = 1;
        for (int i = 0; i < n; ++i) {
        C = C * 2 * (2 * i + 1) / (i + 2);
        }
        return (int)C;
    }
};

class Solution {
public:
    int numTrees(int n) {
        vector<int> G(n+1,0);
        G[0]=G[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;++j){
                G[i]+=G[j-1]*G[i-j];
            }
        }
        return G[n];
    }
};

int main(){

    Solution s;
    cout <<s.numTrees(3)<<endl;


    return 0;
}
