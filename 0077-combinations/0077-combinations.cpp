#define vi vector<int> 
#define vvi vector<vi>
class Solution {
public:
    void rec(int st , vvi &ans , vi &comb , int n , int k){
        if(comb.size() == k){
            ans.push_back(comb);
            return ;
        }
        for(int i = st;i <= n;i++){
            comb.push_back(i);
            rec(i + 1 , ans , comb , n , k);
            comb.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vvi ans;
        vi comb;

        rec(1 , ans , comb , n , k);

        return ans;
    }
};