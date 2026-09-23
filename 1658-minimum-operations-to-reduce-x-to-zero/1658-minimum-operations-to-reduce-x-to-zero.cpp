class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int total = accumulate(nums.begin() , nums.end() , 0);
        int n = nums.size();

        int sum = 0;

        int target = total - x;
        if(target < 0)
            return -1;

        int l = 0 , maxlen = -1;

        for(int r = 0;r < n;r++){
            sum += nums[r];

            while(sum > target){
                sum -= nums[l];
                l++;
            }
            if(sum == target)
                maxlen = max(maxlen , r - l + 1);
        }
        if(maxlen == -1)
            return -1; 
        return n - maxlen;
    }
};