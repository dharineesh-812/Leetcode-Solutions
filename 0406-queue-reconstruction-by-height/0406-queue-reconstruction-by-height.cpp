#define vi vector<int>
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
       sort(people.begin() , people.end(),[](vector<int> &a , vector<int> &b){
            if(a[0] != b[0])
                return a[0] > b[0];
            return a[1] < b[1];
       });
        vector<vi>result;
        for(const vi person : people){
            result.insert(result.begin() + person[1] , person);
        }
        return result;
    }
};