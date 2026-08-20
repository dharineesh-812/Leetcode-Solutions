#define vi vector<int>

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vi>ans;
        for(int mask = 0; mask < (1 << n);mask++){
            vi set;
            for(int i = 0; i < n;i++){
                if(mask & (1 << i))
                    set.push_back(nums[i]);
            }
            ans.push_back(set);
        }
        return ans;
    }
};