#define vi vector<int>
class Solution {
public:
    struct DSU{
        vi parent;
        vi edge;
        vi size;

        void init(int n){
            parent.resize(n);
            edge.resize(n , 0);
            size.resize(n , 1);

            for(int i = 0;i < n;i++)
                parent[i] = i;
        }
        int findroot(int x){
            if(parent[x] == x)
                return x;
            return parent[x] = findroot(parent[x]);
        }
        void merge(int a , int b){
            a = findroot(a);
            b = findroot(b);

            if(a == b)
                return ;
            
            if(size[a] < size[b])
                swap(a , b);
            size[a] += size[b];
            parent[b] = a;
            edge[a] += edge[b] + 1;
        }
    };
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu;
        dsu.init(n);

        for(vi edge : edges){
            int u = edge[0] , v = edge[1];
            int pu = dsu.findroot(u) , pv = dsu.findroot(v);
            if(pu == pv)
                dsu.edge[pu]++;
            else{
                dsu.merge(u , v);
            }
        }
        int ans = 0;
        for(int i = 0;i < n;i++){
            if(i == dsu.parent[i]){
                int v = dsu.size[i];
                int e = v * (v - 1) / 2;
                if(dsu.edge[i] == e)
                    ans++;
            }
        }
        return ans;
    }
};