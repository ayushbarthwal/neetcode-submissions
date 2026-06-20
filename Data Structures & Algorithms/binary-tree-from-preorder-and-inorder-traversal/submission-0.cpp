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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0 || inorder.size()==0) return NULL;
        int mid = find(inorder.begin(),inorder.end(),preorder[0])-inorder.begin();
        TreeNode* root = new TreeNode(preorder[0]);
        vector<int> lp(preorder.begin()+1,preorder.begin()+mid+1);
        vector<int> rp(preorder.begin()+mid+1,preorder.end());
        vector<int> li(inorder.begin(),inorder.begin()+mid);
        vector<int> ri(inorder.begin()+mid+1,inorder.end());
        root->left=buildTree(lp,li);
        root->right=buildTree(rp,ri);
        return root;
    }
};
