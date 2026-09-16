class Solution {
public:
    int dp[2002][2002];
    bool pal[2002][2002];
    int n , k;
    string s;

    bool isPalindrome(int i , int j){
        if(i == j)
            return pal[i][j] = true;
        if(i + 1 == j)
            return pal[i][j] = s[i] == s[j];
        return pal[i][j] = s[i] == s[j] && pal[i + 1][j - 1];
    }
    int rec(int i , int j){
        if(j == n)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = 0;
        int mx = 0;

        if(isPalindrome(i , j) && j - i + 1 >= k){
            ans++;
            mx = rec(j + 1 , j + 1);
        }
        else{
            mx = max(rec(i + 1 , max(i + 1 , j)) , rec(i , j + 1));
        }
        return dp[i][j] = ans + mx;
    }
    int maxPalindromes(string s, int k) {
        n = s.length();
        this -> s = s;
        this -> k = k;

        memset(dp , -1 , sizeof(dp));
        memset(pal , false , sizeof(pal));

        return rec(0 , 0);
    }
};