import java.util.*;
class Solution {
    //int inf = 1000000000;
    public int swimInWater(int[][] grid) {
        int n = grid.length;

        int dx[] = {-1 , 0 , 1 , 0};
        int dy[] = { 0 , 1 , 0 , -1};

        int dist[][] = new int[n][n];

        for(int []row : dist){
            Arrays.fill(row , 1000000000);
        }
        
        dist[0][0] = grid[0][0];

        PriorityQueue <int[]> pq = new PriorityQueue<>((a , b) -> a[0] - b[0]);
        pq.offer(new int[]{grid[0][0] , 0 , 0});

        while(!pq.isEmpty()){
            int []node = pq.poll();

            int t = node[0] , x = node[1] , y = node[2];

            for(int k = 0;k < 4;k++){
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                    int nt = Math.max(grid[nx][ny] , t);

                    if(nt < dist[nx][ny]){
                        dist[nx][ny] = nt;
                        pq.offer(new int[]{nt , nx , ny});
                    }
                }
            }
        }
        return dist[n - 1][n - 1];
    }
}