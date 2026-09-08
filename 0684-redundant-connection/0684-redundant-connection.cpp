#define vi vector<int>
#define pi pair<int,int>
#define F first
#define S second
#define vpi vector<pi>
#define mp make_pair
class Solution {
public:
    
    struct DSU{
        vi parent;
        vi size;
        vpi ans;

        void init(int n){

            parent.resize(n + 1);
            size.assign(n + 1 , 1);

            for(int i = 1; i <= n;i++)
                parent[i] = i;
        }
        int findroot(int x){
            if(parent[x] == x)
                return x;
            return parent[x] = findroot(parent[x]);
        }
        bool merge(int a , int b){
            int pa = findroot(a);
            int pb = findroot(b);
            if(pa == pb){
                ans.push_back(mp(a , b));
                return false;
            }

            if(size[pa] < size[pb])
                swap(pa , pb);

            size[pa] += size[pb];
            parent[pb] = pa;

            return true;
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        DSU dsu;
        dsu.init(n);

        for(vi edge : edges){
            dsu.merge(edge[0] , edge[1]);
        }
        pi it = dsu.ans.back();

        return {it.F , it.S};
    }
};