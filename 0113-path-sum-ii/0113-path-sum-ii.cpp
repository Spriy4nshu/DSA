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
    vector<vector<int>> result;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        helper(root, targetSum, 0, path);
        return result;
    }
    void helper(TreeNode* root, int targetSum, int currSum, vector<int>& path) {
        // base
        if(root == nullptr) return;
        path.push_back(root->val);
        currSum += root->val;
        if(currSum == targetSum && root->left == nullptr && root->right == nullptr){
            result.push_back(path);
        }
        // logic
        helper(root->left, targetSum, currSum, path);
        helper(root->right, targetSum, currSum, path);
        path.pop_back();
    }
};