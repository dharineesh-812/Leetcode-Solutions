#define vi vector<int>
class Solution {
public:
    struct DSU{
        vi parent;
        vi size;
        void init(int n){
            parent.resize(n);
            size.assign(n , 1);
            for(int i = 0; i < n;i++)
                parent[i] = i;
        }
        int findroot(int x){
            if(parent[x] == x)
                return x;
            return parent[x] = findroot(parent[x]);
        }
        bool merge(int a , int b){
            a = findroot(a);
            b = findroot(b);
            if(parent[a] == parent[b])
                return false;
            if(size[a] < size[b])
                swap(a , b);
            parent[b] = a;
            size[b] += size[a];

            return true;
        }
    };
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu;
        dsu.init(n);
        for(int i = 0;i < n;i++){
            for(int j = i + 1;j < n;j++){
                if(isConnected[i][j] == 1){
                    dsu.merge(i , j);
                }
            }
        }
        unordered_set<int> st;
        for(int i = 0;i < n;i++){
            int root = dsu.findroot(i);
            st.insert(root);
        }
        return st.size();
    }
};