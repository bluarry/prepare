#include <bits/stdc++.h>

using namespace std;
struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution1 {
public:
    int TreeDepth(TreeNode* root){
        if(root==NULL) return 0;
        int l=TreeDepth(root->left);
        int r=TreeDepth(root->right);
        return max(l,r)+1;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot==NULL) return true;
        int l=TreeDepth(pRoot->left);
        int r=TreeDepth(pRoot->right);
        if(abs(l-r)>1){
            return false;
        }
        return IsBalanced_Solution(pRoot->left)&&IsBalanced_Solution(pRoot->right);
    }
};

class Solution {
public:
    bool isban(TreeNode* root,int &dep){
        if(root==NULL){
            dep=0;
            return true;
        }
        int l=0,r=0;
        if(isban(root->left,l)&&isban(root->right,r)){
            if(abs(l-r)<=1){
                dep=max(l,r)+1;
                return true;
            }
        }
        return false;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
       int dep=0;
       return isban(pRoot,dep);
    }
};





int main(){




    return 0;
}