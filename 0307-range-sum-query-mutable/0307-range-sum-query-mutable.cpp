#define vi vector<int>
class NumArray {
public:
    vi fen , num;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        fen.resize(n + 1);
        num.resize(n);

        for(int i = 0 ; i < n;i++)
            update(i , nums[i]);
    }
    
    void update(int index, int val) {
        int add = val - num[index];
        num[index] = val;

        index++;

        while(index <= n){
            fen[index] += add;
            index += (index) & (-index);
        }
    }
    int sum(int idx){
        int s = 0;

        while(idx > 0){
            s += fen[idx];
            idx -= (idx) & (-idx);
        }
        return s;
    }
    int sumRange(int left, int right) {
        return sum(right + 1) - sum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */