class Solution {
public:
    using ll = long long;
    vector<ll> dp;
    int mod = 1e9+7;
    int rec(int n){
        if(n < 0)
            return 0;
        if(n == 1)
            return 2;
        if(n == 2)
            return 3;   
        if(dp[n] != -1)
            return dp[n];
        return dp[n] = (rec(n-1) + rec(n-2)) % mod;
    }
    int countHousePlacements(int n) {
        dp.resize(n+1, -1);
        ll ans = rec(n) % mod ;
        return (ans * ans) % mod;
    }
};