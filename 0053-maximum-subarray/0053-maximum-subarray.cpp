class Solution {
public:
    int dp[100005];
    bool check[100005];
    int rec(int i , vector<int> &nums){
        if(i >= nums.size())
            return -1e9;
        if(check[i])
            return dp[i];
        int sum = nums[i];
        sum = max(sum , sum + rec(i + 1 , nums));
        check[i] = 1;
        return dp[i] = sum;
    }
    int maxSubArray(vector<int>& nums) {
        memset(dp , -1 , sizeof(dp));
        memset(check , false , sizeof(check));

        int res = -1e9;
        for(int i = 0;i < nums.size();i++){
            res = max(res , rec(i , nums));
        }
        return res;
    }
};