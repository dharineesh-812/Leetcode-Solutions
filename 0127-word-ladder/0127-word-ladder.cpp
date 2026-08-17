#define all(x) (x).begin(), (x).end()
#define pi pair<string, int>
#define F first
#define S second
class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> st(all(wordList));
        st.erase(beginWord);
        using state = pi;
        queue<state> q;
        q.push({beginWord, 1});
        while (!q.empty()) {
            state sword = q.front();
            q.pop();
            string word = sword.F;
            int cnt = sword.S;
            if (word == endWord)
                return cnt;
            for (int i = 0; i < word.length(); i++) {
                char org = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if (st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, cnt + 1});
                    }
                }
                word[i] = org;
            }
    }
    return 0;
   }
};