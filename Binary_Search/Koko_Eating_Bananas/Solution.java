package Binary_Search.Koko_Eating_Bananas;

class Solution {
    private int res = 0;
    private int getMax(int[] piles) {
        int max_val = Integer.MIN_VALUE;
        for(int i : piles) max_val = Math.max(max_val, i);
        return max_val;
    }
    private long getTime(int[] piles, int k) {
        long cnt = 0;
        for(int i : piles) {
            if(i % k != 0) cnt+= (i / k) + 1;
            else cnt+= i / k;
        }
        return cnt;
    }
    private void getSpeed(int[] piles, int low, int high, int h) {
        if(low > high) return;
        int k = (low + high) >> 1;
        if(getTime(piles, k) <= h) {
            res = k;
            getSpeed(piles, low, k - 1, h);
        } else getSpeed(piles, k + 1, high, h);
    }
    public int minEatingSpeed(int[] piles, int h) {
        getSpeed(piles, 1, getMax(piles), h);
        return res;
    }
}