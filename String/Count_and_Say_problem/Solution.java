import java.util.*;
class Solution {
    public String countAndSay(int n) {
        String s = "1";
        for(int i = 2; i <= n; i++) {
            int c = 1;
            String t = "";
            s+= '&';
            for(int j = 1; j < s.length(); j++) {
                if(s.charAt(j - 1) == s.charAt(j)) c++;
                else {
                    t+= Integer.toString(c);
                    t+= s.charAt(j - 1);
                    c = 1;
                }
            }
            s = t;
        }
        return s;
    }
    public static void main(String[] args) throws Exception {}
}