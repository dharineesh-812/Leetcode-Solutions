class Solution {
    public int smallestIndex(int[] nums) {
        int n = nums.length;

        for(int i = 0;i < n;i++){
            if(check(i , nums[i]))
                return i;
        }
        return -1;
    }
    private boolean check(int i , int x){
        int sum = 0;
        while(x > 0){
            sum += x % 10;
            x = x / 10;
        }
        return i == sum;
    }
}