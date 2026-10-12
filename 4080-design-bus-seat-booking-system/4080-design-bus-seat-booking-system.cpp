#define vi vector<int>
#define vvi vector<vi>
class BusBooking {
public:
    int cnt = 0 , totalTime = 0;
    vvi cost;

    BusBooking(int n) {
        cost.resize(n + 1 , vi(4));
    }
    
    void toggle(string seat) {
        int seatId = seat[0] - 'A';
        int rowId = stoi(seat.substr(1));

        if(cost[rowId][seatId] > 0){
            totalTime -= cost[rowId][seatId];
            cost[rowId][seatId] = 0;
            cnt--;
        }
        else{
            cost[rowId][seatId] = 1;

            if(seatId == 0 && cost[rowId][seatId + 1] > 0){
                cost[rowId][seatId] = 3;                
            }
            if(seatId == 3 && cost[rowId][seatId - 1] > 0){
                cost[rowId][seatId] = 3;
            }
            totalTime += cost[rowId][seatId];
            cnt++;
        }
    }
    
    int getTotalTime() {
        return totalTime;
    }
    
    int getMinTime() {
        return cnt;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */