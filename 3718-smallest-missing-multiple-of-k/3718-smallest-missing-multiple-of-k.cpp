class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st(nums.begin() , nums.end());
        int i = 1 , n = nums.size();
        while(i <= n){
            if(st.find(i * k) == st.end())
                return i * k;
            i++;
        }
        return i * k;
    }
};