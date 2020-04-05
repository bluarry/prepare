#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generate_trees(int start, int end) {
        vector<TreeNode*> all_trees;
        if(start>end){
            all_trees.push_back(NULL);
            return all_trees;
        }

        for(int i=start;i<=end;i++){
            vector<TreeNode*> left_trees=generate_trees(start,i-1);
            vector<TreeNode*> right_trees=generate_trees(i+1,end);

            for(TreeNode* l:left_trees){
                for(TreeNode* r:right_trees){
                    TreeNode *node=new TreeNode(i);
                    node->left=l;
                    node->right=r;
                    all_trees.push_back(node);
                }
            }

        }
        return all_trees;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> no;
        if(n==0){
            return no;
        }
        return generate_trees(1,n);
    }
};

int main(){




    return 0;
}