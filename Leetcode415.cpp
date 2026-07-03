class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.length()-1,m = num2.length()-1;
        string ans = "";
        int car = 0 , sum =0, n1 = 0, n2 =0;
        while(n >= 0 && m >= 0){
             n1 = num1[n] - '0', n2 = num2[m] - '0';
            int total = n1 + n2 + car;
            sum = total % 10;
            car = total / 10;
            ans+=sum + '0';
            n--;
            m--;
        }
        while(n>=0){
            n1 = num1[n] - '0';
            int total = n1 + car;
            sum = total % 10;
            car = total / 10;
            ans +=sum + '0';
            n--;
        }
        while(m>=0){
            n2 = num2[m] - '0';
            int total = n2 + car;
            sum = total % 10;
            car = total / 10;
            ans +=sum + '0';
            m--;
        }
        while(car){
            int total =  car;
            sum = total % 10;
            car = total / 10;
            ans +=sum + '0';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};