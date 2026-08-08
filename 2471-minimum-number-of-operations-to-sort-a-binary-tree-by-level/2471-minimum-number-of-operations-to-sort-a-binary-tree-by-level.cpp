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
    int minimumOperations(TreeNode* root) {
        if(root == NULL)    
            return 0;
        queue<TreeNode*>q;
        q.push(root);
        int cnt = 0;
        while(!q.empty()){
            int n = q.size();
            vector<int>lev;
            for(int i = 0;i < n;i++){
                TreeNode* cur = q.front();
                q.pop();
                lev.push_back(cur -> val);
                if(cur -> left)
                    q.push(cur -> left);
                if(cur -> right)
                    q.push(cur -> right);
            }
            vector<int> slev = lev;
            sort(slev.begin(),slev.end());
            unordered_map<int,int>mp;
            for(int i = 0;i < n;i++)
                mp[lev[i]] = i;
            for(int i = 0;i < n;i++){
                if(slev[i] != lev[i]){
                    cnt++;
                    int n_index = mp[slev[i]];
                    mp[lev[i]] = n_index;
                    swap(lev[i] , lev[n_index]);
                }
            }
        }
        return cnt;
    }
};