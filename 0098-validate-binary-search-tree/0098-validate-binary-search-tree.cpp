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
// class Solution {
// public:
//     bool flag;
//     TreeNode* prev; // nullptr
//     bool isValidBST(TreeNode* root) { 
//         flag = true;
//         helper(root);
//         return flag;
//     }
//     void helper(TreeNode* root) {
//         if(root == nullptr) return;
//         if(flag) {
//             helper(root->left); // inorder traversal
//             if(prev != nullptr && prev->val >= root->val) {
//                 // prev will always be smaller than current (root)
//                 flag = false; 
//             }
//             prev = root;
//         } 
//         if(flag){
//             helper(root->right);
//         }
//     }
// };

// // boolean based recursion
// class Solution {
// public:
//     TreeNode* prev; // nullptr
//     bool isValidBST(TreeNode* root) { 
        
//         return inOrder(root);
//     }
//     bool inOrder(TreeNode* root) {
//         if(root == nullptr) return true;
        
//         bool left = inOrder(root->left); // inorder traversal
//         if(prev != nullptr && prev->val >= root->val) {
//             // prev will always be smaller than current (root)
//             return false; 
//         }
//         prev = root;
        
//         bool right = inOrder(root->right);
//         return (left && right);
//     }
// };

// range based validation
class Solution {
public:
    TreeNode* prev; // nullptr
    bool flag;
    bool isValidBST(TreeNode* root) { 
        this->flag = true;
        inOrder(root, LLONG_MIN, LLONG_MAX);
        return flag;
    }
    void inOrder(TreeNode* root, long long left, long long right) {
        //base
        if(root == nullptr) return;
        if(root->val <= left || root->val >= right){
            flag = false;
            return;
        }
        //logic
        inOrder(root->left, left, root->val);  
        
        inOrder(root->right, root->val, right);   
    }
};