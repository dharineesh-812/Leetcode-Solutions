class Solution {
public:
    int maximumUnits(vector<vector<int>>& box, int truckSize) {
        sort(box.begin(),box.end(),[](vector<int> &a , vector<int> &b){
            return a[1] > b[1];
        });
        int ans = 0;
        for(int i = 0; i < box.size();i++){
            int b = box[i][0] , u = box[i][1];
            if(truckSize >= b){
                truckSize -= b;
                ans = ans + (b * u);
            }
            else if(truckSize > 0 && truckSize < b){
                ans = ans + (truckSize * u);
                truckSize -= truckSize;
            }
            else if(truckSize <= 0)
                break;
        }
        return ans;
    }
};