#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>


using namespace std;

typedef long long ll;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || x%10==0&&x!=0){
            return false;
        }
        ll xx=x,c=0;
        while(xx){
            c=c*10+(xx%10);
            xx/=10;
        }
        return c==x || c==(x/10);
    }
};
int main(){
    Solution s;
    int a;
    while(cin >> a)
        cout << s.isPalindrome(a)<<endl;

    return 0;
}
