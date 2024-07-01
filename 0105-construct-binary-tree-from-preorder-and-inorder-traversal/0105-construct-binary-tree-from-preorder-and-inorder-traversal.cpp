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
        if(preorder.size() == 0) return nullptr;
        //logic
        int rootVal = preorder[0];
        int rootIdx = -1;
        TreeNode* root = new TreeNode(rootVal);
        for(int i = 0; i < inorder.size(); i++) {
            if(inorder[i] == rootVal) {
                rootIdx = i;
                break;
            }
        }
        vector<int> leftIn(inorder.begin(), inorder.begin() + rootIdx);
        vector<int> rightIn(inorder.begin() + rootIdx + 1, inorder.end());
        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + 1 + leftIn.size());
        vector<int> rightPre(preorder.begin() + 1 + leftIn.size(), preorder.end());
        //left call
        root->left = buildTree(leftPre, leftIn);
        root->right = buildTree(rightPre, rightIn);
        return root;
    }
};