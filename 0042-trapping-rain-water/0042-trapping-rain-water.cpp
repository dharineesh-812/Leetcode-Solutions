class Solution {
public:
    int trap(vector<int>& height) {
        int lmax = 0 , rmax = 0;
        int l = 0 , r = height.size() - 1 , trap = 0;

        while(l < r){
            lmax = max(lmax , height[l]);
            rmax = max(rmax , height[r]);

            if(height[l] <= height[r]){
                trap += lmax - height[l];
                l++;
            }
            else{
                trap += rmax - height[r];
                r--;
            }
        }
        return trap;
    }
};