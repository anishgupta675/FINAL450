class Solution {
    long long res = 1e14;
    long long getTrips(vector<int> &time, long long t) {
        long long cnt = 0;
        for(auto i: time) cnt+= t / i;
        return cnt;
    }
    void getTime(vector<int> &time, long long low, long long high, int totalTrips) {
        if(low > high) return;
        long long mid = (low + high) >> 1;
        if(getTrips(time, mid) >= totalTrips) {
            res = mid;
            getTime(time, low, mid - 1, totalTrips);
        } else getTime(time, mid + 1, high, totalTrips);
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        getTime(time, 0, 1e14, totalTrips);
        return res;
    }
};