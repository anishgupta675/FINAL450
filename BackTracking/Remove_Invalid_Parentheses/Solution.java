import java.util.*;

class Solution {

    private List<String> res = new ArrayList<String>();

    private int minRemovals(String s) {
        Stack<Character> st = new Stack<Character>();
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == '(') st.push(s.charAt(i));
            else {
                if(st.isEmpty()) st.push(s.charAt(i));
                else if(st.peek() == ')') st.push(s.charAt(i));
                else if(st.peek() == '(') st.pop();
            }
        }
        return st.size();
    }

    private boolean isValid(String s) {
        Stack<Character> st = new Stack<Character>();
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == '(') st.push(s.charAt(i));
            else {
                if(st.isEmpty()) st.push(s.charAt(i));
                else if(st.peek() == ')') st.push(s.charAt(i));
                else if(st.peek() == '(') st.pop();
            }
        }
        return st.isEmpty();
    }

    private void getUnique(HashSet<String> unique, String s, int mra) {
        if(mra == 0) {
            if(isValid(s)) {
                if(!unique.contains(s)) {
                    res.add(s);
                    unique.add(s);
                }
            }
            return;
        }
        for(int i = 0; i < s.length(); i++) getUnique(unique, s.substring(0, i) + s.substring(i + 1), mra - 1);
    }

    public List<String> removeInvalidParentheses(String s) {
        HashSet<String> unique = new HashSet<String>();
        getUnique(unique, s, minRemovals(s));
        return res;
    }

    public static void main(String[] args) throws Exception {}
}