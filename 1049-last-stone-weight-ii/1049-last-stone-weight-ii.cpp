#define vi vector<int>
class Solution {
public:
    int dp[33][3003];
    int sum , tar;
    
    int rec(int i , int cur , vi &stones){
        if(i >= stones.size())
            return dp[i][cur] = cur;
        if(dp[i][cur] != -1)
            return dp[i][cur];
        
        int take = rec(i + 1 , cur + stones[i] , stones);
        int skip = rec(i + 1 , cur , stones);

        if(abs(tar - take) < abs(tar - skip))
            return dp[i][cur] = take;
            
        return dp[i][cur] = skip;
    }
    int lastStoneWeightII(vector<int>& stones) {
        memset(dp , -1 , sizeof(dp));

        sum = accumulate(stones.begin(),stones.end(),0);
        tar = sum / 2;
        
        int ans = rec(0 , 0 , stones);

        return abs(sum - (2 * ans));
    }
};