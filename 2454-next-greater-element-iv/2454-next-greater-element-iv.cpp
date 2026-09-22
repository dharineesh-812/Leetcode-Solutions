#define vi vector<int>
class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();

        vi ans(n , -1);

        stack<int> st1 , st2 , tmp;

        for(int i = 0;i < n;i++){
            while(!st2.empty() && nums[st2.top()] < nums[i]){
                ans[st2.top()] = nums[i];
                st2.pop();
            }
            while(!st1.empty() && nums[st1.top()] < nums[i]){
                tmp.push(st1.top());
                st1.pop();
            }
            while(!tmp.empty()){
                st2.push(tmp.top());
                tmp.pop();
            }
            st1.push(i);
        }
        return ans;
    }
};