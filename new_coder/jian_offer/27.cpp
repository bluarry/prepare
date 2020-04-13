#include <bits/stdc++.h>

using namespace std;
//二叉树与双向链表 

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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode *treelast=NULL;
        helper(pRootOfTree,&treelast);

        TreeNode *p=treelast;
        while(p&&p->left)p=p->left;
        return p;
    }
    /*更改root为根节点的树为双向链表，并用treelast执行树的最大值节点*/
    void helper(TreeNode* root,TreeNode** treelast){
        if(root==NULL){return;}
        TreeNode *node=root;
        if(node->left){
            helper(node->left,treelast);
        }
        node->left=*treelast;
        if(*treelast){
            (*treelast)->right=node;
        }
        *treelast=node;
        if(node->right){
            helper(node->right,treelast);
        }
    }
};
void cust(TreeNode* &p){
    p=new TreeNode(10);
    p->left=new TreeNode(6);
    p->right=new TreeNode(14);
    TreeNode *q=p->left;
    q->left=new TreeNode(4);
    q->right=new TreeNode(8);
    q=p->right;
    q->left=new TreeNode(12);
    q->right=new TreeNode(16);
}


int main(){
    TreeNode* p=NULL;
    cust(p);    
    Solution s;
    TreeNode *q=s.Convert(p);
    while(q){
        cout <<q->val <<endl;
        q=q->right;
    }
    return 0;
}