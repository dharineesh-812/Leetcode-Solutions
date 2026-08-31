class Solution {
public:
    int dp[102];
    int rec(int i , string &s){
        if(i == 0)
            return 1;
        if(i == 1)
            return s[i - 1] != '0' ? 1 : 0;
        if(dp[i] != -1)
            return dp[i];
        int ways = 0;
        if(s[i - 1] != '0')
            ways += rec(i - 1 , s);
        if(s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] <= '6')
            ways += rec(i - 2 , s);
        return dp[i] = ways;
    }
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0')
            return 0;
        memset(dp , -1 , sizeof(dp));
        int n = s.length();
        return rec(n , s);
    }
};