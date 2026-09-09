#define vi vector<int>
class Solution {
public:
    struct DSU{
        vi parent;
        vi size;
        
        void init(){
            parent.resize(26);
            size.resize(26 , 1);

            for(int i = 0;i < 26;i++)
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
    bool equationsPossible(vector<string>& equations) {
        DSU dsu;
        dsu.init();

        for(string &s : equations){
            if(s[1] == '=')
                dsu.merge(s[0] - 'a' , s[3] - 'a');
        }
        for(string &s : equations){
            if(s[1] == '!'){
                int a = s[0] - 'a', b = s[3] - 'a';
                a = dsu.findroot(a);
                b = dsu.findroot(b);
                if(a == b)
                    return false;
            }
        }
        return true;
    }
};