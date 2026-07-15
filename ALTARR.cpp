#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> nums(n);
        int cnt1 =0,cnt2 = 0;
        for(int i =0;i <n;i++) {
            cin>>nums[i];
        }
        for(int i = 0;i < n;i++){
            int curr = nums[i] % 2;
            int exp = i % 2;
            if(curr!=exp)
                cnt1++;
            else
                cnt2++;
        }
        cout<<min(cnt1,cnt2)<<endl;
    }
}
