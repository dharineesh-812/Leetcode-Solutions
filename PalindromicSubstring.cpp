class Solution {
public:
    int countSubstrings(string s) {
         int n = s.length() , cnt = 0;
         vector<vector<int>>dp(n,vector<int>(n,0));
        for(int d = 0;d < n;d++){
            for(int i = 0 , j = i + d;j < n && i < n;j++ , i++){
                if(i == j)
                    dp[i][j] = 1;
                else if(d == 1){
                    if(s[i] == s[j])
                        dp[i][j] = 2;
                }
                else{
                    if(s[i] == s[j] && dp[i+1][j-1] != 0)
                        dp[i][j] = 2 + dp[i + 1][j - 1];
                }
                if(dp[i][j] != 0)
                    cnt++;
            }v
        }
        return cnt;
    }
};