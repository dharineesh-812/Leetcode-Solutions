class Solution {
public:
    int dp[25][25];
    int m , n;
    bool rec(int i , int j , string &s , string &p){
        if(j == n)
            return i == m;
        if(dp[i][j] != -1)
            return dp[i][j];
        bool firstM = (i < m && (s[i] == p[j] || p[j] =='.'));

        if(j + 1 < n && p[j + 1] == '*'){
            bool zero = rec(i , j + 2 , s , p);
            bool more = firstM && rec(i + 1 , j , s , p);
            return dp[i][j] = zero || more;
        }
        if(firstM)
            return dp[i][j] = rec(i + 1 , j + 1 , s , p);
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        m = s.length() , n = p.length();
        memset(dp , -1 , sizeof(dp));
        return rec(0 , 0 , s ,p);
    }
};