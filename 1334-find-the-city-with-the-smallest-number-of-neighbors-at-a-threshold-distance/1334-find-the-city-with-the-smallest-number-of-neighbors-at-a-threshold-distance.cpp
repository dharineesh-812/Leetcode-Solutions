#define vi vector<int>
const int inf = 1e9;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vi> dist(n , vi(n , inf));
        for(int i = 0;i < n;i++)
            dist[i][i] = 0;
        for(vi edge : edges){
            int u = edge[0] , v = edge[1] , w = edge[2];

            dist[u][v] = w;
            dist[v][u] = w;
        }
        for(int k = 0; k < n;k++){
            for(int i = 0;i < n;i++){
                for(int j = 0;j < n;j++){
                    dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
                }
            }
        }
        int res = -1;
        int reach = n;

        for(int i = 0; i < n;i++){
            int count = 0;
            for(int j = 0;j < n;j++){
                if(i != j && dist[i][j] <= distanceThreshold){
                    count++;
                }
            }
            if(count <= reach){
                reach = count;
                res = i;
            }
        }
        return res;
    }
};