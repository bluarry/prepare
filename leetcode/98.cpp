#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;




struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution1 {
public:
    bool find(TreeNode* root,int* lower,int* upper){
        if(root==NULL) return true;
        if(lower!=NULL && root->val <= *lower) return false;
        if(upper!=NULL && root->val >= *upper) return false;
        if(!find(root->right,&root->val,upper)) return false;
        if(!find(root->left,lower,&root->val)) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
      return find(root,NULL,NULL);
    }
};


class Solution2 {
public:
    queue<TreeNode*> que;
    queue<int*> lowers,uppers;
    void enq(TreeNode* root,int* lower,int* upper){
        que.push(root);
        lowers.push(lower);
        uppers.push(upper);
    }


    bool isValidBST(TreeNode* root) {
        int* lower=NULL,upper=NULL;
        
        enq(root,lower,upper);

        while(!que.empty()){
            root=que.front();que.pop();
            lower=lowers.front();lowers.pop();
            upper=uppers.front();uppers.pop();
            
            if(root==NULL) continue;
            if(lower!=NULL && root->val <=lower) return false;
            if(upper!=NULL && root->val >=upper) return false;

            enq(root->left,lower,&root->val);
            enq(root->right,&root->val,upper);
        }
        return true;
    }
};

class Solution3 {
public:
    vector<int> q;
    void tr(TreeNode* root){
        if(root==NULL) return;
        tr(root->left);
        q.push_back(root->val);
        tr(root->right);
    }
    bool isValidBST(TreeNode* root) {
        tr(root);
        for(int i=0;i<q.size();i++){
            for(int j=i+1;j<q.size();j++){
                if(q[j]<=q[i]){
                    return false;
                }
            }
        }
        return true;
    }
};

class Solution {
public:

    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        long long m=INT64_MIN;
        while(!s.empty()|| root!=NULL){
            while(root!=NULL){
                s.push(root);
                root=root->left;
            }

            root=s.top();s.pop();

            if(root->val <= m) return false;

            m=root->val;
            root=root->right;
        }
        return true;
    }
};

class Solution4
{
public:
    bool isValidBST(TreeNode* root) 
    {
        return dfs(root,INT_MIN,INT_MAX);
    }

    bool dfs(TreeNode* root,long long minv,long long maxv)
    {
        if(!root) return true;
        if(root->val < minv || root->val > maxv) return false;
        
        //[负无穷，x - 1]和[x + 1,正无穷]中寻找
        return dfs(root->left,minv,root->val - 1ll) && dfs(root->right,root->val + 1ll,maxv);
    }
};

int main(){




    return 0;
}