class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0 , l = 0;
        unordered_map<char , int> mp;
        for(int i = 0; i < s.length();i++){
            if(mp.find(s[i]) != mp.end() && mp[s[i]] >= l){
                l = mp[s[i]] + 1;
            }
            len = max(len ,i - l + 1);
            mp[s[i]] = i;
        }
        return len;
    }
};