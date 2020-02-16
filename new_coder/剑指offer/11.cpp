#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    double Mypow(double a,int b){
        //b>=0
        double res=1;
        while(b){
            if(b&1) res*=a;
            a*=a;
            b>>=1;
        }
        return res;
    }
    
    
    double Power(double a, int e) {
        if(e>=0)
            return Mypow(a,e);
        else
            return 1.0/Mypow(a,-e);
    }
};


int main(){
	Solution s;
	cout << s.Power(1.2,-1)<<endl;
	
	
	return 0;
}
