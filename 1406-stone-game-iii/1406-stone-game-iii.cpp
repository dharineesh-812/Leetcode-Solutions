class Solution {
public:
    vector<int>dp;
    // int rec(vector<int> &value , int i){
    //     cout<<i<<" ";
    //     if(i >= value.size())
    //         return 0;
    //     if(dp[i] != INT_MAX)
    //         return dp[i];
    //     int one = value[i] - rec(value , i + 1);
    //     int two = INT_MIN , three = INT_MIN;
    //     if(i + 1 < value.size())
    //         two = value[i] + value[i + 1] - rec(value , i + 2);
    //     if(i + 2 < value.size())
    //         three = value[i] + value[i + 1] + value[i + 2] - rec(value , i + 3);
    //     return dp[i] = max({one , two , three});
    // }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.assign(n + 1, INT_MAX);
        dp[n] = 0;
        for(int i = n - 1; i>=0 ;i--){
            int one = stoneValue[i] - dp[i + 1];
            int two = INT_MIN , three = INT_MIN;
            if(i + 1 < n)
                two = stoneValue[i] + stoneValue[i + 1] - dp[i + 2];
            if(i + 2 < n)
                three = stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3];
            dp[i] = max({one , two , three});
        }
        if(dp[0] < 0)
            return "Bob";
        if(dp[0] > 0)
            return "Alice";
        return "Tie";
    }
};