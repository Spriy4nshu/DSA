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
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         // base
//         if(preorder.size() == 0) return nullptr;
//         // logic
//         int rootVal = preorder[0];
//         int rootIdx = -1;
//         TreeNode* root = new TreeNode(rootVal);
//         for(int i = 0; i < inorder.size(); i++) {
//             if(inorder[i] == rootVal) {
//                 rootIdx = i;
//                 break;
//             }
//         }
//         vector<int> leftIn(inorder.begin(), inorder.begin() + rootIdx);
//         vector<int> rightIn(inorder.begin() + rootIdx + 1, inorder.end());
//         vector<int> leftPre(preorder.begin() + 1, preorder.begin() + 1 + leftIn.size());
//         vector<int> rightPre(preorder.begin() + 1 + leftIn.size(), preorder.end());
//         //left call
//         root->left = buildTree(leftPre, leftIn);
//         root->right = buildTree(rightPre, rightIn);
//         return root;
//     }
// };

class Solution {
public:
    int idx;
    unordered_map<int, int> map;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->idx = 0;
        for(int i = 0; i < preorder.size(); i++) {
            this->map.emplace(make_pair(inorder[i], i));
        }
        return helper(preorder, 0, preorder.size() - 1);
    }
private:
    TreeNode* helper(vector<int>& preorder, int start, int end) {
        // base
        if(start > end) return nullptr;
        // logic
        int rootVal = preorder[idx];
        idx++;
        TreeNode* root = new TreeNode(rootVal);
        int rootIdx = map[rootVal];
        root->left = helper(preorder, start, rootIdx - 1);
        root->right = helper(preorder, rootIdx + 1, end);
        return root;
    }
};