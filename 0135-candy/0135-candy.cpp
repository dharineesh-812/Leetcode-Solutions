#define vi vector<int>
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vi left(n , 1);
        for(int i = 1;i < n;i++){
            if(ratings[i] > ratings[i - 1]){
                left[i] = 1 + left[i - 1];
            }
        }
        for(int i = n - 2; i >= 0;i--){
            if(ratings[i] > ratings[i + 1]){
                left[i] = max(left[i] ,1 + left[i + 1]);
            }
        }
        int ans = accumulate(left.begin() , left.end() , 0);
        return ans;
    }
};