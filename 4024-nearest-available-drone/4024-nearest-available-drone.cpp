class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int mn = INT_MAX , mi = -1;
        int tx = target[0] , ty = target[1];
        for(int i = 0;i < drones.size();i++){
            auto d = drones[i];
            int x = d[0] , y = d[1] , r = d[2];
            int dist = abs(x - tx) + abs(y - ty);

            if(dist <= r && dist < mn){
                mi = i;
                mn = dist;
            }
        }
        return mi;
    }
};