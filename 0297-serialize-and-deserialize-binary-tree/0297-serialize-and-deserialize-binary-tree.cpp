/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Codec {
// public:

//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         if(root == NULL)
//             return "null";
//         queue<TreeNode*>q;
//         q.push(root);
//         string res;
//         while(!q.empty()){

//                 TreeNode* cur = q.front();
//                 q.pop();
//                 if(cur){
//                     res += to_string(cur -> val) + ",";
//                     q.push(cur -> left);
//                     q.push(cur -> right);
//                 }
//                 else
//                     res+= "null,";
                
//             }
        
//         return res;
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         if(data == "null")
//             return NULL;
//         string token;
//         stringstream ss(data);
//         getline(ss , token, ',');
//         TreeNode* root = new TreeNode(stoi(token));
//         queue<TreeNode*>q;
//         q.push(root);
//         while(!q.empty()){
//             TreeNode* cur = q.front();
//             q.pop();
//             if(!getline(ss , token , ',')) break;
//                 if(token != "null"){
//                     cur -> left = new TreeNode(stoi(token));
//                     q.push(cur -> left);
//                 }
//             if(!getline(ss , token , ',')) break;
//                 if(token != "null"){
//                     cur -> right = new TreeNode(stoi(token));
//                     q.push(cur -> right);
//                 }
//         }
//         return root;
//     }
// };
class Codec {
public:

    string serialize(TreeNode* root) {
        if (root == NULL)
            return "null";

        queue<TreeNode*> q;
        q.push(root);

        string res;

        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();

            if (cur != NULL) {
                res += to_string(cur->val) + ",";
                q.push(cur->left);
                q.push(cur->right);
            } else {
                res += "null,";
            }
        }

        return res;
    }

    TreeNode* deserialize(string data) {
        if (data == "null")
            return NULL;

        stringstream ss(data);
        string token;

        getline(ss, token, ',');

        TreeNode* root = new TreeNode(stoi(token));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();

            // Left child
            getline(ss, token, ',');

            if (token != "null") {
                cur->left = new TreeNode(stoi(token));
                q.push(cur->left);
            }

            // Right child
            getline(ss, token, ',');

            if (token != "null") {
                cur->right = new TreeNode(stoi(token));
                q.push(cur->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));