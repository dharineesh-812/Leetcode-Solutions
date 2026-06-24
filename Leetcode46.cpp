class Solution {
public:
    void find(vector<int>& nums,vector<vector<int>>& ans,vector<int>& ds,vector<int>& freq){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return ;
        }
        for(int i = 0;i < nums.size();i++){
            if(freq[i]) 
                continue;
            freq[i] = 1;
            ds.push_back(nums[i]);
            find(nums,ans,ds,freq);
            freq[i] = 0;
            ds.pop_back();

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>> ans;
         vector<int>ds;
         vector<int>freq(nums.size(),0);
         find(nums,ans,ds,freq);
         return ans;
    }
};