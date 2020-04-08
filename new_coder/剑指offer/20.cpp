#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> ans;
		int row=matrix.size(),col=matrix[0].size();
		int left=0,right=col-1,top=0,bottom=row-1;
		if(row==0||col==0) return ans;
		while(left<=right&&top<=bottom){
			for(int i=left;i<=right;i++){
				//cout << matrix[top][i] <<" ";
				ans.push_back(matrix[top][i]);
			}
			if(top<bottom){
				for(int i=top+1;i<=bottom;i++){
					// cout << matrix[i][right] <<" ";
					ans.push_back(matrix[i][right]);
				}
			}
			if(top<bottom && left<right){
				for(int i=right-1;i>=left;--i){
					// cout << matrix[bottom][i] <<" ";
					ans.push_back(matrix[bottom][i]);
				}
			}
			if(top<bottom-1 && left<right){
				for(int i=bottom-1;i>=top+1;i--){
					// cout << matrix[i][left] <<" ";
					ans.push_back(matrix[i][left]);	
				}
			}
			left++,right--,top++,bottom--;
		}
		return ans;
    }
};



int main(){
	vector<vector<int> > a={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	
	Solution s;
	s.printMatrix(a);
	
	return 0;
}
