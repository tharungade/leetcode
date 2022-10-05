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
    void func(TreeNode* root, int val, int depth)
    {
        if(!root) return;
    
        if(depth == 0)
        {
            TreeNode* newNode1  = new TreeNode(val,root->left,NULL);
            TreeNode* newNode2 = new TreeNode(val,NULL,root->right);
            root->left = newNode1;
            root->right = newNode2;
            return;
        }
        
            func(root->left,val,depth-1);
            func(root->right,val,depth-1);
        
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1)
        {
            TreeNode* newRoot = new TreeNode(val,root,NULL);
            return newRoot;
        }
        
        func(root,val,depth-2);
        return root;
    }
};