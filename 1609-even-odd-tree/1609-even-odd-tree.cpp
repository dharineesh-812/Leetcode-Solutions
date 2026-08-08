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
    bool isEvenOddTree(TreeNode* root) {
        if(root == NULL)
            return true;
        queue<TreeNode*>q;
        q.push(root);
        int xr = 1;
        while(!q.empty()){
            int n = q.size();
            stack<int> st;
            for(int i = 0;i < n;i++){
                TreeNode* cur = q.front();
                q.pop();
                if(xr){
                    if(cur -> val % 2 == 0 || (!st.empty() && st.top() >= cur -> val))
                        return false;
                    st.push(cur -> val);
                }
                else{
                    if(cur -> val & 1 || (!st.empty() && st.top() <= cur -> val))
                        return false;
                    st.push(cur -> val);
                }
                if(cur -> left)
                    q.push(cur -> left);
                if(cur -> right)
                    q.push(cur -> right);
            }
            xr ^= 1;
        }
        return true;
    }
};