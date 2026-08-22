#define vs vector<string>
#define vb vector<bool>
#define ps pair<int , string>
#define F first
#define S second
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        vs result;
        vector<ps> pairs;
        int n = friends.size();
        vb vis(n , false);
        vis[id] = 1;
        queue<int>q;
        q.push(id);
        unordered_map<string , int>mp;
        while(!q.empty() && level--){
            int si = q.size();
            while(si--){
                int ids = q.front();
                q.pop();
                for(auto i : friends[ids]){
                    if(!vis[i]){
                        vis[i] = 1;
                        q.push(i);
                    }
                }
            }
        }
        while(!q.empty()){
            int ids = q.front();
            q.pop();
            for(string &s : watchedVideos[ids])
                mp[s]++;
        }
        for(auto it = mp.begin(); it != mp.end() ;it++){
            pairs.push_back({it->S , it->F});
        }
        sort(pairs.begin(),pairs.end());
        for(int i = 0;i < pairs.size();i++){
            result.push_back(pairs[i].S);
        }
        return result;
    }
};