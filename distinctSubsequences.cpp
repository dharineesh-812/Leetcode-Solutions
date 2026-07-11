class Solution {
public:
    int dp[1001][1001];
    int rec(string &s, string &t,int i,int j){
        if(j == t.length())
            return 1;
        if(i >=s.length())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int take = 0,skip =0;
        if(s[i] == t[j])
        take = rec(s,t,i + 1,j+1);
        skip = rec(s,t,i+1,j);
        return dp[i][j] = take + skip;
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return rec(s,t,0,0);
    }
};