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
#define pi pair<int,int>
#define F first 
#define S second
class Solution {
public:
    int ans;
    pi rec(TreeNode* root){
        if(root == NULL)
            return {0 , 0};
        
        pi left = rec(root -> left);
        pi right = rec(root -> right);

        int sum = left.F + right.F + root -> val;
        int n = left.S + right.S + 1;

        if(root -> val == sum / n)
            ans++;
        return {sum , n};
    }
    int averageOfSubtree(TreeNode* root) {
        if(root == NULL)
            return 0;
        ans = 0;
        rec(root);
        return ans;
    }
};