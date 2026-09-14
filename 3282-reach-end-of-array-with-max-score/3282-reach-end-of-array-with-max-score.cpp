class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        using ll = long long;
        int prev = 0 , n = nums.size();
        ll ans =  0;
        for(int i = 1;i < n;i++){
            if(nums[i] > nums[prev]){
                ans += 1LL * (i - prev) * nums[prev];
                prev = i;
            }
        }
        if(prev != n - 1)
            ans += 1LL * (n - 1 - prev) * nums[prev];

        return ans;
    }
};