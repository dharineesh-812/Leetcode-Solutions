#define vs vector<string>
#define vvs vector<vs>
#define pb push_back
class Solution {
public:
    bool isPalin(int l , int r , string &s){
        while(l < r){
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    void rec(int idx , string &s , vs &cur , vvs &ans){
        if(idx == s.length()){
            ans.pb(cur);
            return ;
        }
        for(int i = idx;i < s.length();i++){
            if(isPalin(idx , i , s)){
                string temp = s.substr(idx , i - idx + 1);
                cur.pb(temp);
                rec(i + 1 , s , cur , ans);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vvs ans;
        vs cur;
        rec(0 , s , cur , ans);
        return ans;
    }
};