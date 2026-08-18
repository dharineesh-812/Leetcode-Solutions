class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int num : nums)
            mp[num]++;
        int ans = -1;
        if(n == k)
            return *max_element(nums.begin(),nums.end());
        if(k == 1){
            for(int num : nums){
                if(mp[num] != 1)
                    continue;
                ans = max (ans , num);
            }
            return ans;
        }
        if(mp[nums[0]] == 1 && mp[nums[n - 1]] == 1)
            return max(nums[0] , nums[n - 1]);
        if(mp[nums[0]] == 1)
            return nums[0];
        if(mp[nums[n - 1]] == 1)
            return nums[n - 1];

        return -1;
    }
};