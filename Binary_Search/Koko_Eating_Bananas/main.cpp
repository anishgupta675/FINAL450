class Solution {
    int res = 0;
    int getMin(int a, int b) { return (a < b) ? a : b; }
    int getMax(int a, int b) { return (a > b) ? a : b; }
    int getMax(vector<int> &piles) {
        int max_val = INT_MIN;
        for(int i : piles) max_val = getMax(max_val, i);
        return max_val;
    }
    long getTime(vector<int> &piles, int k) {
        long cnt = 0;
        for(int i : piles) {
            if(i % k) cnt+= (i / k) + 1;
            else cnt+= i / k;
        }
        return cnt;
    }
    void getSpeed(vector<int> &piles, int low, int high, int h) {
        if(low > high) return;
        int k = (low + high) >> 1;
        if(getTime(piles, k) <= h) {
            res = k;
            getSpeed(piles, low, k - 1, h);
        } else getSpeed(piles, k + 1, high, h);
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        getSpeed(piles, 1, getMax(piles), h);
        return res;
    }
};