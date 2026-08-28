#define vi vector<int>

class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vi> ans;
        for(int i = 0;i < (1 << n);i++){
            vi st;
            for(int mask = 0; mask < n;mask++){
                if(i & (1 << mask))
                    st.push_back(nums[mask]);
            }
            ans.push_back(st);
        }
        return ans;
    }
};