class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int bit = 0;bit < 32;bit++){
            int countOne = 0;
            for(int num : nums){
                if((num >> bit) & 1)
                    countOne++;
            }
            int countzero = n - countOne;
            ans += countzero * countOne;
        }
        return ans;
    }
};