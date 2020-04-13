#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;



class Solution1 {
public:
     int NumberOf1(int n) {
         int res=0;
         unsigned int r=1;
         while(r){
         	if(n&r) res++;
         	r<<=1;
		 }
		 return res;
     }
};
class Solution {
public:
     int NumberOf1(int n) {
         int res=0;
         while(n){
         	++res;
         	n=(n-1)&n;
		 }
         
         return res;
     }
};
int main(){
	Solution s;
	int n;
	while(cin>> n)
		cout << "ans: "<<s.NumberOf1(n)<<endl;
	return 0;
} 
