#define vi vector<int>
#define pi pair<int,int>
#define mp make_pair
#define F first
#define S second
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vi ans;
        using state = pi;
        priority_queue<state> pq;
        map<int,int>mpp;
        for(int i = 0;i < nums.size();i++){
            mpp[nums[i]]++;
        }
        for(state it : mpp){
            pq.push(mp(it.S , it.F));
        }
        while(k--){
            state it = pq.top();
            pq.pop();
            ans.push_back(it.S);
        }
        return ans;
    }
};