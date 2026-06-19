/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int c = 0, res = -1;
    void helper(TreeNode *root, int t){
        if(!root || c>t) return;
        helper(root->left,t);
        c++;
        if(c==t){
            res = root->val;
            return;
        }
        helper(root->right,t);
    }
    int kthSmallest(TreeNode* root, int k) {
        helper(root,k);
        return res;
    }
};
