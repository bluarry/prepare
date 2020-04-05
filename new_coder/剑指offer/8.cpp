#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


class Solution1 {
public:
	int ff(vector<int> A){
		int n=A.size()-1,low=A[1];
		for(int i=0;i<=n;i++){
			low=min(low,A[i]);
		}
		return low;
	}
	
    int minNumberInRotateArray(vector<int> A) {
        int low=0,high=A.size()-1,mid;
        if(A.size()==0) return 0;
		if(A[low]!=A[high]){
				while(low+1!=high){
	    		mid=(low+high)/2;	
	    		
				if(A[mid]<=A[high]){
					high=mid;
				}else if(A[mid]>=A[low]){
					low=mid;
				}
			
			}
			return min(A[high],A[low]);
		}else{
			return ff(A);
		}
	    
	}
};



class Solution {
public:
	int ff(vector<int> A,int l,int r){
		int n=A.size()-1,low=A[l];
		for(int i=l;i<=r;i++){
			low=min(low,A[i]);
		}
		return low;
	}
	
    int minNumberInRotateArray(vector<int> A) {
        int low=0,high=A.size()-1,mid=0;
        if(A.size()==0) return 0;
        while(A[low]>=A[high]){
        	if(high-low==1){
        		mid=high;
        		break;
			}
			
			mid=low+(high-low)/2;
			
			if(A[low]==A[high]&& A[high]==A[mid]) return ff(A,low,high);
			
			if(A[mid]<=A[high]){
				high=mid;
			}else if(A[mid]>=A[low]){
				low=mid;
			}
		}
        return A[mid];
	}
};


int main(){
	vector<int> a={2,2,2,2,2,2};	
	Solution s;		
	cout << s.minNumberInRotateArray(a) << endl;

	return 0;
}
