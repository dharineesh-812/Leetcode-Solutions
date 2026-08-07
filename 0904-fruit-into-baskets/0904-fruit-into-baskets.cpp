class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0;
        unordered_map<int,int>mp;
        int cnt = 0 , l = 0 ;
        for(int r = 0;r < fruits.size();r++){
            mp[fruits[r]]++;
            if(mp[fruits[r]] == 1)
                cnt++;
            while(cnt > 2){
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0)
                    cnt--;
                l++;
            }
            if(cnt <= 2){
                ans = max(ans , r - l + 1);
            }
        }
        return ans;
    }
};