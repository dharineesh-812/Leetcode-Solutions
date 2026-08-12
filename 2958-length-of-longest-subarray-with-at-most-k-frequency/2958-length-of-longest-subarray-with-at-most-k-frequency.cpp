class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int ans = 0 , l = 0;
        for(int r = 0;r < nums.size();r++){
            mp[nums[r]]++;
            while(mp[nums[r]] > k){
                mp[nums[l]]--;
                l++;
            }
            if(mp[nums[r]] <= k)
                ans = max(ans , r - l + 1);
        }
        return ans;
    }
};