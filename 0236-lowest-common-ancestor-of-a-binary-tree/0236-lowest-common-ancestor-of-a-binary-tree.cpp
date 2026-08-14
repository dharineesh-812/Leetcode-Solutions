/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* check(TreeNode* root , TreeNode* p , TreeNode* q){
        if(root == nullptr || root == p || root == q)
            return root;
        TreeNode* left = check(root -> left , p , q);
        TreeNode* right = check(root -> right , p , q);
        if(!left) return right;
        else if(!right)  return left;
        return root;        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return check(root , p , q);
    }
};