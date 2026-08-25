class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        for(char digit : num){
            while(k > 0 && !st.empty() && st.back() > digit){
                st.pop_back();
                k--;
            }
            st.push_back(digit);
        }
        while(k > 0){
            st.pop_back();
            k--;
        }
        int i = 0;
        while(i < st.size() && st[i] == '0')
            i++;
        if(i == st.size())
            return "0";
        return st.substr(i);
    }
};