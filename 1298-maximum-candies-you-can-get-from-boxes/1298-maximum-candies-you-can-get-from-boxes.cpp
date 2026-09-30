class Solution {
public:
    int dfs(int i , vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes){
        int ans = candies[i];

        status[i] = 0;

        for(int k : keys[i]){
            status[k] |= 1;
            if(status[k] == 3)
                ans += dfs(k , status , candies , keys , containedBoxes , initialBoxes);
        }
        for(int c : containedBoxes[i]){
            status[c] |= 2;
            if(status[c] == 3)
                ans += dfs(c , status , candies , keys , containedBoxes , initialBoxes);
        }
        return ans;
    }
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = keys.size();

        int ans = 0;

        for(int c : initialBoxes){
            status[c] |= 2;
            if(status[c] == 3)
                ans += dfs(c , status , candies , keys , containedBoxes , initialBoxes);
        }
        return ans;
    }
};