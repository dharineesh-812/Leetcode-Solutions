class Solution {
public:
    void dfs(int open , int close , string s , int n , vector<string> &res){
        if(open == close && open + close == 2 * n){
            res.push_back(s);
            return ;
        }
        if(open < n)
            dfs(open + 1 , close , s + '(' , n , res);
        if(close < open)
            dfs(open , close + 1 , s + ')' , n , res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(0 , 0 , "" , n , res);
        return res;
    }
};