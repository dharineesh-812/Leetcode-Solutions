class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd = 0 , even = 0;
        for(int i = 0; i < nums1.size();i++){
            if(nums1[i] & 1)
                odd++;
            else 
                even++;
        }
        if(odd == nums1.size() || even == nums1.size())
            return true;
        
        int small = *min_element(nums1.begin(),nums1.end());
        if(small % 2 == 0)
            return false;
        return true;
    }
};