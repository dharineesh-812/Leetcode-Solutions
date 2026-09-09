
#define vvs vector<vector<string>>
#define vi vector<int>
class Solution {
public:
    struct DSU{
        vi parent;
        vi size;

        void init(int n){
            parent.resize(n);
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

            parent[b] = a;
            size[a] += size[b];
        }
    };
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vvs ans;
        unordered_map<string , int> mp;
        int n = accounts.size();

        DSU dsu;
        dsu.init(n);

        for(int i = 0;i < n;i++){
            for(int j = 1;j < accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mp.find(mail) == mp.end())
                    mp[mail] = i;
                else
                    dsu.merge(mp[mail] , i);
            }
        }
        vector<string> merged[n];

        for(auto &it : mp){
            string mail = it.first;
            int node = dsu.findroot(it.second);
            merged[node].push_back(mail);
        }
        for(int i = 0;i < n;i++){
            if(merged[i].empty())
                continue;
            sort(merged[i].begin() , merged[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for(auto &mail : merged[i]){
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};