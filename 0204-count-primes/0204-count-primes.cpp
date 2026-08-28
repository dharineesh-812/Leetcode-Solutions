class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)
            return 0;
        bool prime[n];
        memset(prime , true , sizeof(prime));

        for(int i = 2;i * i < n;i++){
            if(prime[i]){
                for(int j = i * i; j < n;j += i){
                    prime[j] = 0;
                }
            }
        }

        int cnt = 0;

        for(int i = 2;i < n;i++)
            if(prime[i])
                cnt++;
        return cnt;
    }
};