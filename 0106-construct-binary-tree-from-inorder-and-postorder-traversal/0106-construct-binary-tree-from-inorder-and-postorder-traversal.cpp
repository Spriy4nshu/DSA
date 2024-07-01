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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size() == 0) return nullptr;
        //logic
        int rootVal = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootVal);
        int rootIdx = -1;
        for(int i = 0; i < postorder.size(); i++) {
            if(inorder[i] == rootVal) {
                rootIdx = i;
                break;
            }
        }
        vector<int> leftIn(inorder.begin(), inorder.begin() + rootIdx);
        vector<int> rightIn(inorder.begin() + 1 + rootIdx, inorder.end());
        vector<int> leftPost(postorder.begin(), postorder.begin() + leftIn.size());
        vector<int> rightPost(postorder.begin() + leftIn.size(), postorder.end() - 1);
        // left recurse
        root->left = buildTree(leftIn, leftPost);
        // right recurse
        root->right = buildTree(rightIn, rightPost);
        return root;
    }
};