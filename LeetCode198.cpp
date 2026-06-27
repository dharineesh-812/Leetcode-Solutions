class Solution {
public:
 
    int rob(vector<int>& nums) {
        int n = nums.size();
        int ans = 0,sum = 0;
        if(n == 1)
            return nums[0];
        int prev = nums[0];
        int prev2 = 0;
        for(int i = 1; i < n;i++){
            sum = nums[i];
            if(i > 1)
                sum +=prev2;
            int npick = prev;
            int curr = max(sum , npick);
            prev2 = prev;
            prev = curr;

        }
        return prev;
    }
};