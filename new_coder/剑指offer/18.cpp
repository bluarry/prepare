#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	bool check(TreeNode* p, TreeNode* q){
		if(q==NULL) return true;
		if(p==NULL) return false;
		
		if(p->val != q->val) return false;
		
		
		return check(p->left,q->left) && check(p->right,q->right);
	}
    bool HasSubtree(TreeNode* p, TreeNode* q)
    {
		bool res=false;
		
		if(p!=NULL && q!=NULL){
			if(p->val==q->val){
				res=check(p,q);
			}
			if(!res) res=HasSubtree(p->left,q);
			if(!res) res=HasSubtree(p->right,q);
		}
		return res;
    }
};

void btp(TreeNode *p){
	p->right=new TreeNode(7);
	
	p->left=new TreeNode(8);
	
	p=p->left;
	
	p->left=new TreeNode(9);
	p->right=new TreeNode(2);
	p=p->right;
	p->left=new TreeNode(4);
	p->right=new TreeNode(7);
	
}
void btq(TreeNode *q){
	q->left=new TreeNode(9);
	q->right=new TreeNode(2);
}

int main(){
	TreeNode *p=new TreeNode(8);
	TreeNode *q=new TreeNode(8);
	btp(p);
	btq(q);
	
	Solution s;
	
	s.HasSubtree(p,q);
	
	return 0;
}
