#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
pre{1,2,4,7,3,5,6,8},vin{4,7,2,1,5,3,8,6};
*/
class Solution {
public:
	TreeNode* buildtree(vector<int> pre,int s,int d,vector<int> vin,int ss,int dd){
	//	cout << "s: "<<s << " d: " <<d<<" ss: "<<ss << " dd: " <<dd  <<endl;
		if(s>d||ss>dd|| s<0||ss<0||s>=pre.size()||ss>=pre.size()) return NULL;
		TreeNode* root=new TreeNode(pre[s]);
		int m;
		
		for(m=ss;vin[m]!=pre[s];m++);    //在中序遍历中找到前序遍历的第一个数字 
		
		root->left=buildtree(pre,s+1,m-ss+s,vin,ss,m-1);
		root->right=buildtree(pre,m-ss+s+1,d,vin,m+1,dd);
				
		
		return root;
	}
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
		int n=pre.size();
		return buildtree(pre,0,n-1,vin,0,n-1);
    }
};

void preorder(TreeNode* root){
	if(root!=NULL){
		cout <<root->val<< endl;
		preorder(root->left);
		preorder(root->right);
	}
}

void swap(int &a,int &b){
	int tmp=a;
	a=b;
	b=tmp;
}

int main(){
	vector<int> pre{1,2,4,7,3,5,6,8},vin{4,7,2,1,5,3,8,6};
	Solution s;
	TreeNode* root=s.reConstructBinaryTree(pre,vin);
	
	preorder(root);
	
	
	
	return 0;
}
