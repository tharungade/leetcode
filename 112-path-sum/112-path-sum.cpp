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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        while(q.size() > 0)
        {
            auto curr = q.front();
            if(!((curr.first)->left) && !((curr.first)->right) && (curr.second) == targetSum)
                return true;
                
            if((curr.first)->left)
                q.push({(curr.first)->left, (curr.second + ((curr.first)->left)->val)});
            
            if((curr.first)->right)
                q.push({(curr.first)->right, (curr.second + ((curr.first)->right)->val)});
            
            q.pop();
        }
        
        return false;
    }
};