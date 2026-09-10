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
    int sum = 0;
    void rec(TreeNode* root){
        if(root == NULL)
            return ;
        rec(root -> right);

        sum = sum + root -> val;
        root -> val = sum;

        rec(root -> left);      

    }
    TreeNode* bstToGst(TreeNode* root) {
        if(root == NULL)
            return NULL;
        rec(root);
        return root;
    }
};