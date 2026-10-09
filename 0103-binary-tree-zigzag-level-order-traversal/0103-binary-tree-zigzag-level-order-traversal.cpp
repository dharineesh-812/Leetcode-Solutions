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
#define vi vector<int>
#define pb push_back
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vi> ans;

        if(root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        int rev = 0;
        while(!q.empty()){
            int n = q.size();
            vi level;

            while(n--){
                TreeNode* node = q.front();
                q.pop();

                level.pb(node -> val);

                if(node -> left)
                    q.push(node -> left);
                if(node -> right)
                    q.push(node -> right);
            }
            if(rev)
                reverse(level.begin() , level.end());
            
            rev ^= 1;
            ans.pb(level);
        }
        return ans;
    }
};