#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <deque>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution1 {
public:
    
    void  travel(TreeNode* root,vector<int> &nums){
        if(root==NULL) return ;
        travel(root->left,nums);
        nums.push_back(root->val);
        travel(root->right,nums);
    }
    void find(vector<int> &nums,vector<int>&v){
        int x=INT_MIN,y=INT_MIN;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]<nums[i]){
                y=nums[i+1];
                if(x==INT_MIN) x=nums[i];
                else break;
            }
        }
        v[0]=x;
        v[1]=y;
    }
    void recover(TreeNode* root,int c,int x,int y){
        if(root!=NULL){
            if(root->val==x||root->val==y){
                root->val= root->val==x?y:x;
                if(--c==0) return ;
            }
            recover(root->left,c,x,y);
            recover(root->right,c,x,y);
        }
    }
    void recoverTree(TreeNode* root) {
        vector<int> nums;
        //首先获取中序数组
        travel(root,nums);
        //定位两个需要交换的数字
        vector<int> ans(2,0);
        find(nums,ans);
        //中序遍历改数字
        recover(root,2,ans[0],ans[1]);
    }
};

class Solution2 {
public:
    
    void recoverTree(TreeNode* root) {
        deque<TreeNode*> q;
        TreeNode *x=NULL,*y=NULL,*pre=NULL; //交换节点x,y和前驱节点

        while(!q.empty() || root!=NULL){
            while(root!=NULL){
                q.push_back(root);
                root=root->left;
            }

            root=q.back();q.pop_back();
            if(pre!=NULL && root->val < pre->val){
                y=root;
                if(x==NULL){x=pre;}
                else break;
            }
            pre=root;
            root=root->right;
        }
        int t=x->val;
        x->val=y->val;
        y->val=t;
    }
};
class Solution3 {
public:
    TreeNode *x,*y,*pre;
    void find(TreeNode* root) {
        if(root==NULL) return ;
        find(root->left);
        if(pre!=NULL && pre->val > root->val){
            y=root;
            if(x==NULL){
                x=pre;
            }else return;
        }
        pre=root;
        find(root->right);
    }
    void recoverTree(TreeNode* root) {
        x=y=pre=NULL;
        find(root);
        swap(&x->val,&y->val);
    }
};



class Solution {
  public void swap(TreeNode a, TreeNode b) {
    int tmp = a.val;
    a.val = b.val;
    b.val = tmp;
  }

  public void recoverTree(TreeNode root) {
    // predecessor is a Morris predecessor. 
    // In the 'loop' cases it could be equal to the node itself predecessor == root.
    // pred is a 'true' predecessor, 
    // the previous node in the inorder traversal.
    TreeNode x = null, y = null, pred = null, predecessor = null;

    while (root != null) {
      // If there is a left child
      // then compute the predecessor.
      // If there is no link predecessor.right = root --> set it.
      // If there is a link predecessor.right = root --> break it.
      if (root.left != null) {
        // Predecessor node is one step left 
        // and then right till you can.
        predecessor = root.left;
        while (predecessor.right != null && predecessor.right != root)
          predecessor = predecessor.right;

        // set link predecessor.right = root
        // and go to explore left subtree
        if (predecessor.right == null) {
          predecessor.right = root;
          root = root.left;
        }
        // break link predecessor.right = root
        // link is broken : time to change subtree and go right
        else {
          // check for the swapped nodes
          if (pred != null && root.val < pred.val) {
            y = root;
            if (x == null) x = pred;
          }
          pred = root;

          predecessor.right = null;
          root = root.right;
        }
      }
      // If there is no left child
      // then just go right.
      else {
        // check for the swapped nodes
        if (pred != null && root.val < pred.val) {
          y = root;
          if (x == null) x = pred;
        }
        pred = root;

        root = root.right;
      }
    }
    swap(x, y);
  }
}

/**
 * 
 * 利用二叉树的空指针线索二叉树,这样不需要递归直接遍历树
*/
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *x=NULL,*y=NULL,*pred=NULL,*predecessor=NULL;
        while(root!=NULL){
            if(root->left!=NULL){
                predecessor=root->left;
                while(predecessor->right!=NULL && predecessor->right!=root){
                    predecessor=predecessor->right;
                }
                if(predecessor->right==NULL){
                    predecessor->right=root;
                    root=root->left;
                }else{
                    if(pred!=NULL &&root->val <pred->val){
                        y=root;
                        if(x==NULL) x=pred;
                    }
                    pred=root;  
                    predecessor->right=NULL;
                    root=root->right;
                }
            }else{
                if(pred!=NULL &&root->val <pred->val){
                    y=root;
                    if(x==NULL) x=pred;
                }
                pred=root;
                root=root->right;
            }
        }
        swap(x->val,y->val);
    }
};



int main(){




    return 0;
}