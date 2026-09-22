class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = grumpy.size();

        int base = 0;
        for(int i = 0;i < n;i++){
            if(grumpy[i] == 0)
                base += customers[i];
        }
        int extra = 0;
        for(int i = 0;i < minutes;i++){
            if(grumpy[i] == 1)
                extra += customers[i];
        }
        int maxextra = extra;
        for(int i = minutes;i < n;i++){
            if(grumpy[i] == 1)
                extra += customers[i];
            if(grumpy[i - minutes] == 1)
                extra -= customers[i - minutes];
            
            maxextra = max(maxextra , extra);
        }
        return base + maxextra;
    }
};