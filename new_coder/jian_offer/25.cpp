#include <bits/stdc++.h>

using namespace std;

/**
 *二叉树找路径？ 
 * 
 */

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
    vector<vector<int> > ans;
    void find(TreeNode* root,int expectNumber,vector<int> v,int NowSum){
        if(root==NULL) return ;
        NowSum+=root->val;
        v.push_back(root->val);
        bool isLeaf= (root->left==NULL &&root->right==NULL);
        if(NowSum==expectNumber && isLeaf){
            ans.push_back(v);
        }

        if(root->left!=NULL){
            find(root->left,expectNumber,v,NowSum);
        }

        if(root->right!=NULL){
            find(root->right,expectNumber,v,NowSum);
        }
        NowSum-=root->val;
        v.pop_back();
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        ans.clear();
        vector<int> v;
        find(root,expectNumber,v,0);
        return ans;
    }
};

void t(TreeNode* &root){
    root=new TreeNode(10);
    root->left=new TreeNode(5);
    root->right=new TreeNode(12);
    TreeNode *l=root->left;
    l->left=new TreeNode(4);
    l->right=new TreeNode(7);
}


int main(){
    TreeNode* root=NULL;
    t(root);
    Solution s;
    vector<vector<int> > vv= s.FindPath(root,22);
    for(vector<int> V:vv){
        for(int a : V){
            cout <<a << " ";
        }
        cout << endl;
    }

    return 0;
}