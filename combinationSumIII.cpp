class Solution {
public:
    void find(vector<vector<int>> &ans , int sum , int last, vector<int>nums , int size){
        if(sum ==  0 && nums.size() == size){
            ans.push_back(nums);
            return;
        }
        if(sum<=0 || nums.size()>size)
            return ;
        for(int i = last ;i <=9 ;i++){
            if(i<=sum){
                nums.push_back(i);
                find(ans,sum-i,i+1,nums,size);
                nums.pop_back();
            }
            else
                break;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums ;
        vector<vector<int>>ans;
        find(ans,n,1,nums,k);
        return ans;
    }
};