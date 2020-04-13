#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
    	if(n>=2)
		{
			vector<vector<int> > res=mypow(n);
			return res[0][0];
		}
		return n==0?0:1;
    }
private:
	vector<vector<int> > mul(const vector<vector<int> > &a,const vector<vector<int> > &b){
		vector<vector<int> > res={{0,0},{0,0}};
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++){
				for(int k=0;k<2;k++){
					res[i][j]+=a[i][k]*b[k][j];
				}
			}
		return res;
	}
	vector<vector<int> >mypow(int n){
		vector<vector<int> > v{{1,1},{1,0}};
		vector<vector<int> > res{{1,0},{0,1}};
		while(n){
			if(n&1) res=mul(res,v);
			v=mul(v,v);
			n>>=1;
		}
		return res;
	}
};

int main(){
	Solution s;
	int n;
	while(cin >> n){
		cout <<"ans: "<<  s.Fibonacci(n)<<endl;
	}
	
	return 0;
}
