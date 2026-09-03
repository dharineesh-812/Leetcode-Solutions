#define pi pair<int,string>
#define mp make_pair
#define F first
#define S second
class Solution {
public:
    struct cmp{
        bool operator()(const pi &p1 , const pi &p2)const{
            if(p1.F == p2.F)
                return p1.S > p2.S;
            return p1.F < p2.F;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mpp;
        using state = pi;

        priority_queue<state , vector<state> ,cmp> q;
        for(int i = 0;i < words.size();i++){
            mpp[words[i]]++;
        }
        for(auto it : mpp){
            q.push(mp(it.S , it.F));
        }
        vector<string> ans;

        while(k--){
            state it = q.top();
            q.pop();
            ans.push_back(it.S);
        }
        return ans;
    }
};