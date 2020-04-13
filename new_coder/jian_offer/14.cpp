#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


class SolutionA {
public:
    void reOrderArray(vector<int> &ar) {
    	int len=ar.size();
    	if(len==0) return;
    	int l=0,r=len-1;
    	while(l<r){
    		while(l<r && (ar[l]&1)==1) l++;
    		while(l<r && (ar[r]&1)==0) r--;
    		
    		if(l<r){
    			swap(ar[l],ar[r]);
			}
    		
		} 
		    
    }
};
class Solution {
public:
    void reOrderArray(vector<int> &ar) {
    	int len = ar.size();
    	int r=len-1,l=len-1;
    	while(l>=0){
    		if(l==0 &&(ar[l]&1) ==1) return;
    		while(l>=0 && (ar[l]&1) ==1 )l--;
    		if(l<0 ) return;
    		int k=ar[l];
    		int i=l--;
    		while(i<r){
    			ar[i]=ar[i+1];
    			i++;
			}
			ar[r--]=k;
		}
    }
};


int main(){
	Solution s;
	vector<int> a={2,4,6,1,3,5,7};
	//vector<int> a={1,2,3,4,5,6,7};
	
	s.reOrderArray(a);
	
	for(int x:a){
		cout << x <<endl;
	}
	
	
	return 0;
}
