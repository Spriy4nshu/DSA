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
    bool flag;
    TreeNode* prev; // nullptr
    bool isValidBST(TreeNode* root) { 
        flag = true;
        helper(root);
        return flag;
    }
    void helper(TreeNode* root) {
        if(root == nullptr) return;
        if(flag) {
            helper(root->left); // inorder traversal
            if(prev != nullptr && prev->val >= root->val) {
                // prev will always be smaller than current (root)
                flag = false; 
            }
            prev = root;
        } 
        if(flag){
            helper(root->right);
        }
    }
};