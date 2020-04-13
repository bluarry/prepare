#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;


class Solution1 {
	public:
		bool fi(int t,vector<vector<int> > array,int r,int c){
			int m=array.size(),n=array[0].size();
			if(r<0|| c<0||r>=m||c>=n) return false;
			
			if(array[r][c]==t) return true;
			
			if(array[r][c]>t){
				return (fi(t,array,r,c-1) );	
			}else if(array[r][c]<t){
				return (fi(t,array,r+1,c));
			}
			return false;
		}
		bool Find(int target, vector<vector<int> > array) {
				return fi(target,array,0,array[0].size()-1);
		}
};


class Solution2 {
	public:
		bool Find(int target, vector<vector<int> > array) {
			int m=array.size(),n=array[0].size();	
			int r=0,c=n-1;
			while(r<m&& c>=0){
				if(array[r][c]==target){
					return true;
				}
				if(array[r][c]>target) c--;
				else r++;
			}
			
			return false;
		}
};

#include <algorithm>
class Solution {    //¶Î´íÎó?? 
	public:
		bool Find(int target, vector<vector<int> > array) {
			if(array.empty()||array[0].empty()) return false;
			int m=array.size(); 
			for(int i=0;i<m;i++){
				vector<int>::iterator res=lower_bound(array[i].begin(),array[i].end(),target);
				if(*res ==target) return true;
			}
			return false;
		}
};

int main() {
	vector<vector<int> > array {{},{},{},{}};
	Solution s;
	int t=10;
	while(1){
		int tt;
		cin >> tt;
		bool re= s.Find(tt,array);
		if(re)
			cout <<"true"<<endl;
		else cout << "flase"<<endl;
	}
	return 0;
}
