class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res;
        for(int i = 0;i < num;i++){
            int n = min(sum , 9);
            res += to_string(n);
            sum -= n;
        }
        if(sum == 0)
            return res;
        return "";
    }
};