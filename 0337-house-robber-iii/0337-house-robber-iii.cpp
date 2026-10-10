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
    unordered_map<TreeNode* , int> dp;
    int rec(TreeNode* root){
        if(root == NULL)
            return 0;
        if(dp.count(root))
            return dp[root];
        
        int take = root -> val;

        if(root -> left){
            take += rec(root -> left -> left) + rec(root -> left -> right);
        }
        if(root -> right)
            take += rec(root -> right -> left) + rec(root -> right -> right);
        int skip = 0;
        if(root -> left)
            skip += rec(root -> left);
        if(root -> right)
            skip += rec(root -> right);

        return dp[root] = max(skip , take);
    }
    int rob(TreeNode* root) {
        return rec(root);
    }
};