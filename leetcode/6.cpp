#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>


using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(0==x) return 0;
        int res=0;
        while(x!=0){
            
            if(res>INT32_MAX/10 || (res==INT32_MAX && (x%10)>7) ) return 0;
            if(res<INT32_MIN/10 || (res==INT32_MIN && (x%10)<-8)) return 0;
            res=res*10+(x%10);
            x/=10;
        }
        return res;
    }
};


int main(){
    int x;
    Solution s;
    while(cin >> x){
        cout << s.reverse(x) << endl;
    }
    return 0;
}
