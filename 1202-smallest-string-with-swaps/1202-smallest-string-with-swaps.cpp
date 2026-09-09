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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();

        DSU dsu;
        dsu.init(n);

        unordered_map <int , vector<char>> mp;
        string ans(n , '.');
        for(vi it : pairs){
            dsu.merge(it[0] , it[1]);
        }
        for(int i = 0;i < n;i++){
            mp[dsu.findroot(i)].push_back(s[i]);
        }
        for(auto &it : mp){
            sort(it.second.rbegin() , it.second.rend());
        }
        for(int i = 0; i < n;i++){
            ans[i] = mp[dsu.findroot(i)].back();
            mp[dsu.findroot(i)].pop_back();
        }
        return ans;
    }
};