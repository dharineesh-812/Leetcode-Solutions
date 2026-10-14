class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0;i < n;i++)
            nums[i] *= nums[i];
        sort(nums.begin() , nums.end());
        long long ans = 0;
        for(int i = 0, j = n - 1;i <= j;i++ , j--){
            ans += nums[j];

            if(i != j)
                ans -= nums[i];
        }
        return ans;
    }
};