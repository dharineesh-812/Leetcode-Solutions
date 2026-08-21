#define all(x) (x).begin() , (x).end()
#define pi pair<string , int>
#define mp make_pair
#define F first
#define S second
class Solution {
public:
    char ch[4] = {'A' , 'C' , 'G' , 'T'};
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(all(bank));
        st.erase(startGene);

        using state = pi;

        queue<state> q;
        q.push(mp(startGene , 0));
        while(!q.empty()){
            state it = q.front();
            q.pop();
            string gene = it.F;
            int cnt = it.S;
            if(gene == endGene)
                return cnt;
            for(int i = 0; i < gene.length();i++){
                char org = gene[i];
                for(char c : ch){
                    gene[i] = c;
                    if(st.find(gene) != st.end()){
                        st.erase(gene);
                        q.push(mp(gene , cnt + 1));
                        
                    } 
                }
                gene[i] = org;
            }
        }
        return -1;
    }
};