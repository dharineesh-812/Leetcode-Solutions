class Solution {
public:
    const int mod = 1e9 + 7;
    int dp[2001][54][54];
    int rec(vector<int>& nums , int i , int li , int ld){
        if(i == nums.size())
            return 1;
        if(dp[i][li][ld] != -1)
            return dp[i][li][ld];
        int ans = 0;
        for(int j = li; j <= nums[i];j++){
            int x1 = j , x2 = nums[i] - j;
            if(x1 >= li && x2 <= ld)
                ans = (ans + rec(nums , i + 1 , x1 , x2)) % mod;
        }
        return dp[i][li][ld] = ans;
    }
    int countOfPairs(vector<int>& nums) {
        memset(dp , -1 ,sizeof(dp));
        return rec(nums , 0 , 0 , 50);
    }
};