class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0 , len = 0;
        unordered_map<int , int> mp;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] == 0)
                sum = sum - 1;
            else
                sum += 1;
            if(sum == 0)
                len = max(len , i + 1);
            else if(mp.count(sum))
                len = max(len , i - mp[sum]);
            else if(mp.find(mp[sum]) == mp.end())
                mp[sum] = i;
        }
        return len;
    }
};