class Solution {
public:
    long long countCommas(long long n) {
        long long res = 0 , s = 1000;

        while(s <= n){
            res += n - s + 1;
            s = s * 1000;
        }
        return res;
    }
};