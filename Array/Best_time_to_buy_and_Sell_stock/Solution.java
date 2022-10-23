import java.util.*;
class Solution {
    public int maxProfit(int[] prices) {
        int current_sum = prices[0], max_sum = 0;
        for(int i = 0; i < prices.length; i++) {
            if(current_sum > prices[i]) current_sum = prices[i];
            else max_sum = Math.max(max_sum, prices[i] - current_sum);
        }
        return max_sum;
    }
    public static void main(String[] args) throws Exception {}
}