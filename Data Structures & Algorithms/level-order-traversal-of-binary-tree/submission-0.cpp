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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            vector<int> l;
            int s = q.size();
            for(int i = 0; i<s; i++){
                TreeNode *c = q.front();
                if (c->left!=NULL){q.push(c->left);}
                if (c->right!=NULL){q.push(c->right);}
                l.push_back(c->val);
                q.pop();
            }
            res.push_back(l);
        }
        return res;
    }
};
