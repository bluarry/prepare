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
        int s=0;
        for(int i=0;i<(int)prices.size()-1;i++){
            s+= prices[i+1]>prices[i]?prices[i+1]-prices[i]:0;
        }
        return s;
    }
};

int main(){
    Solution s;
    vector<int> v={7,1,5,3,6,4};
    cout << s.maxProfit(v)<<endl;
    return 0;
}