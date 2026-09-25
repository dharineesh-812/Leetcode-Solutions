class Solution {
public:
    int reverseDegree(string s) {
        int cnt = 1 , ans = 0;
        for(int x : s){
            int id = 26 - (x - (int)'a');
            ans += cnt * id;
            cnt += 1;
        }
        return ans;
    }
};