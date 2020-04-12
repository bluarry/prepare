#include <iostream>
#include <bits/stdc++.h>

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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> v;
        if(root==NULL ) return v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* r=q.front();q.pop();
            if(r==NULL) continue;
            v.push_back(r->val);
            q.push(r->left);q.push(r->right);
        }
        return v;
    }
};



int main(){




    return 0;
}