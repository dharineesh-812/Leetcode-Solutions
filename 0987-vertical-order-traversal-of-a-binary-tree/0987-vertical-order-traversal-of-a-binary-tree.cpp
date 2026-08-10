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
    void check_hd(TreeNode* root , int &min , int &max , int hd){
        if(root == NULL)
            return ;
        if(min > hd)    min = hd;
        if(max < hd)    max = hd;

        if(root -> left)
            check_hd(root -> left, min , max , hd - 1);
        if(root -> right)
            check_hd(root -> right , min , max , hd + 1);
    }
    void verLn(TreeNode* root , int dist , vector<int>& ver){
        int hd = 0;
        vector<pair<int,int>>temp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root , {0,0}});
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            TreeNode *node = cur.first;
            hd = cur.second.first;
            int row = cur.second.second;
            if(hd == dist)
                temp.push_back({row , node->val});
            if(node -> left)
                q.push({node -> left , {hd - 1 , row + 1}});
            if(node -> right)
                q.push({node -> right , {hd + 1 , row + 1}});
        }
        sort(temp.begin(),temp.end());
        for(auto p : temp){
            ver.push_back(p.second);
        }
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int min = 0 , max = 0;
        vector<vector<int>>ans;
        check_hd(root , min , max , 0);
        for(int i = min ;i <= max;i++){
            vector<int> ver;
            verLn(root , i , ver);
            ans.push_back(ver);
        }
        return ans;
    }
};