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
using ll = long long;
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<ll,vector<ll> , greater<ll>>pq;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            ll sum = 0;
            for(int i = 0;i < n;i++){
                TreeNode * cur = q.front();
                q.pop();
                sum += cur -> val;
                if(cur -> left)
                    q.push(cur -> left);
                if(cur -> right)
                    q.push(cur -> right);
            }
            pq.push(sum);
            if(pq.size() > k)
                pq.pop();
        }
        if(pq.size() < k)
            return -1;
        // for(int i = 0;i < k - 1;i++)
        //     st.erase(--st.end());
        return pq.top();
    }
};