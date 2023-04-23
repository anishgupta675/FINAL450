import java.util.*;

class Solution {

    private int res_low = 0;
    private int res_high = 0;
    private int res_len = 0;

    private void longestPalindrome(String s, int low, int high) {
        if(low < 0 || high >= s.length() || s.charAt(low) != s.charAt(high)) return;
        if(high - low + 1 > res_len) {
            res_low = low;
            res_high = high;
            res_len = high - low + 1;
        }
        longestPalindrome(s, low - 1, high + 1);
    }

    public String longestPalindrome(String s) {
        if(s.length() == 1) return s;
        for(int i = 0; i < s.length(); i++) {
            longestPalindrome(s, i, i);
            longestPalindrome(s, i, i + 1);
        }
        return s.substring(res_low, res_high + 1);
    }

    public static void main(String[] args) throws Exception {}
}