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
    void func(TreeNode* root, vector<int> &sortedArr)
    {
        if(!root) return;
        
        func(root->left, sortedArr);
        sortedArr.push_back(root->val);
        func(root->right, sortedArr);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> sortedArr;
        func(root,sortedArr);
        
        int low = 0, high = sortedArr.size()-1;
        while(low < high)
        {
            if(sortedArr[low] + sortedArr[high] == k)
                return true;
            
            if(sortedArr[low] + sortedArr[high] > k)
                high--;
            else
                low++;
        }
        
        return false;
    }
};