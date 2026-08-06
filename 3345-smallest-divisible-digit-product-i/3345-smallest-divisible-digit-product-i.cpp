class Solution {
public:
    int smallestNumber(int n, int t) {
        int ans = 0;
        for(int i = n;i <= n + 100;i++){
            int x = i;
            int res = 1;
            while(x>0){
                res = res * (x % 10);
                x /= 10;
            }
            if(res % t == 0)
                return i;
        }
        return -1;
    }
};