class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if(dividend == divisor)  return 1;        
        if(dividend == INT_MIN && divisor == -1)  return INT_MAX;
        if(divisor == 1)  return dividend;

        int sign = 1;

        if(dividend >= 0 && divisor < 0)
            sign = -1;        
        if(dividend < 0 && divisor > 0)
            sign = -1;
        
        long long n = dividend;
        long long d = divisor;

        n = abs(n);
        d = abs(d);

        long long sum = 0 , ans = 0;

        while(n >= d){
            long long val = d;
            long long mul = 1;

            while((val << 1) <= n){
                val <<= 1;
                mul <<= 1;
            }
            n -= val;
            ans += mul;
        }
        if(sign == -1)
            return 0 - ans;
        return ans;
    }
};