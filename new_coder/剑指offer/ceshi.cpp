#include<iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int pow4(int a,int b){
  int r=1,base=a;
  while(b){
    if(b&1) r*=base;
    base*=base;
    b>>=1;
  }
  return r;
}




int main() {
	//vector<vector<int> > array={{1,2,3,4,5},{1,2,3,4}};
	
	
//	for (vector<int> x : array) 
//	{
//		for(int i : x)
//			cout<< i<<" ";
//		cout <<endl;
//	}		
	vector<int> a={1,2,3,4};
	swap(a[0],a[1]);
	cout << a[0]<<endl;
	
	
	return 0;
}



