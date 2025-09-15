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
    
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        ans(root, maxi);
        return maxi;
    }
    int ans(TreeNode* root, int& maxi){
        if(root == NULL) return 0;

        int left = ans(root -> left, maxi);
        int right = ans(root -> right, maxi);
        maxi = max(maxi, left + right);
        return 1 + max(left, right);
    }
};