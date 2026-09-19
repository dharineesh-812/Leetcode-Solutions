#define vi vector<int>
#define pb push_back
class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int n1 = n / 2 , n2 = n - n1;

        vector<vi> left(n1 + 1) , right(n2 + 1);
        for(int mask = 0;mask < (1 << n1);mask++){
            int sum = 0;
            int sz = 0;
            for(int i = 0;i < n1;i++){
                if(mask & (1 << i)){
                    sum += nums[i];
                    sz++;
                }
            }
            left[sz].pb(sum);
        }

        for(int mask = 0;mask < (1 << n2);mask++){
            int sum = 0;
            int sz = 0;
            for(int i = 0;i < n2;i++){
                if(mask & (1 << i)){
                    sum += nums[n1 + i];
                    sz++;
                }
            }
            right[sz].pb(sum);
        }
        for(int i = 0;i <= n2;i++)
            sort(right[i].begin() , right[i].end());
        int total = accumulate(nums.begin() , nums.end() , 0);

        for(int i = 1;i <= n1;i++){
            if((total * i) % n != 0)
                continue;
            int target = (total * i) / n;
            for(int l = 0;l <= i;l++){
                int r = i - l;
                if(r > (n1 - l))
                    continue;
                for(int j : left[l]){
                    int x = target - j;
                    auto it = lower_bound(right[r].begin() , right[r].end() , x);

                    if(it != right[r].end() && *it == x)
                        return true;
                }
            }
        }
        return false;
    }
};