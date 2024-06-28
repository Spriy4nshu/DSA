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
    int sum;
    int sumNumbers(TreeNode* root) {
        helper(root, 0);
        return sum;
    }
    void helper(TreeNode* root, int curr) {
        //base 
        if(root == nullptr) return;
        curr = curr*10 + root->val;
        //logic
        if(root->left == nullptr && root->right == nullptr){
            sum += curr;
        }
        helper(root->left, curr);
        helper(root->right, curr);
        
    }
};