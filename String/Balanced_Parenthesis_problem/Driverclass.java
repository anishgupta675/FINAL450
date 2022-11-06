//{ Driver Code Starts
import java.util.*;
import java.io.*;
import java.lang.*;

class Driverclass
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        
        //Reading total number of testcases
        int t= sc.nextInt();
        
        while(t-- >0)
        {
            //reading the string
            String st = sc.next();
            
            //calling ispar method of Paranthesis class 
            //and printing "balanced" if it returns true
            //else printing "not balanced"
            if(new Solution().ispar(st) == true)
                System.out.println("balanced");
            else
                System.out.println("not balanced");
        
        }
    }
}
// } Driver Code Ends




class Solution
{
    static boolean validator(Character x, Character y) {
        if(x == '{' && y == '}') return true;
        if(x == '(' && y == ')') return true;
        if(x == '[' && y == ']') return true;
        return false;
    }
    //Function to check if brackets are balanced or not.
    static boolean ispar(String X)
    {
        // add your code here
        Character temp;
        Stack<Character> stack = new Stack<Character>();
        for(int i = 0; i < X.length(); i++) {
            if(stack.empty()) stack.push(X.charAt(i));
            else if(X.charAt(i) == '{' || X.charAt(i) == '(' || X.charAt(i) == '[') stack.push(X.charAt(i));
            else if(X.charAt(i) == '}' || X.charAt(i) == ')' || X.charAt(i) == ']') {
                if(stack.empty() || !validator(stack.peek(), X.charAt(i))) return false;
                temp = stack.pop();
            }
        }
        return stack.empty();
    }
}
