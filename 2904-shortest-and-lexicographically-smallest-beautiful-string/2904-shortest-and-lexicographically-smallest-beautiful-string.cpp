class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";

        int l = 0 , one = 0;

        for(int r = 0;r < s.length();r++){
            if(s[r] == '1')
                one++;
            
            while(one > k){
                if(s[l] == '1')
                    one--;
                l++;
            }

            if(one == k){

                while(l < r && s[l] == '0')
                    l++;
                string cur = s.substr(l , r - l + 1);

                if((ans == "" )|| (cur.length() < ans.length()) || ((cur.length() == ans.length()) && (cur < ans)))
                    ans = cur;
            }
        }
        return ans;
    }
};