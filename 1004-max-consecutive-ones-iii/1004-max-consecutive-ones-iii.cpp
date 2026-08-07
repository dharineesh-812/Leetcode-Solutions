class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size() , cnt = 0 , l = 0 ,ans = 0;
        for(int r = 0; r < n;r++){
            if(nums[r] == 0)
                cnt++;
            while(cnt > k){
                if(nums[l] == 0)
                    cnt--;
                l++;
            }
            if(cnt <= k)
                ans = max(ans , r - l + 1);
        }
        return ans;
    }
};