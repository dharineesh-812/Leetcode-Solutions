class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0 , s = 0 , p = 1;
        int num = n;
        while(n > 0){
            s += (n % 10);
            p = p * (n % 10);
            n /= 10;
        }
        sum = s + p;
        if(num % sum == 0)
            return true;
        return false;
    }
};