class Solution {
public:
    int dp[int(1e5 + 5)];
    int rec(int n){
        if(n < 0)
            return 1e9;
        
        if(n == 0)
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
        
        int ans = 1e9;

        for(int x = 1; x * (x + 1) <= 2 * n; x += 1){
            int sum = x * (x + 1) / 2;
            ans = min(ans , x + 1 + rec(n - sum));
        }
        return dp[n] = ans;
    }
    int minDays(int n) {
        memset(dp , -1 , sizeof(dp));

        return rec(n) - 1;
    }
};