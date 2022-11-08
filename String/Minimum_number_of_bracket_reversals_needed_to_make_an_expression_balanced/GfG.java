//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
class GfG
{
    public static void main (String[] args)
    {
        
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            String s = sc.next ();
    		System.out.println (new Sol().countRev (s));
        }
        
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


//User function Template for Java

class Sol
{
    int countRev (String s)
    {
        // your code here       
        int count=0;

        Stack<Character> st = new Stack<>();

        for(int i=0; i<s.length(); i++){

            if(!st.empty()){

                if(st.peek()=='{' && s.charAt(i)=='}'){

                    st.pop();

                    continue;

                }    

            }

            st.push(s.charAt(i));

        }

        

        int size=st.size();

        if(size%2 != 0)

            return -1;

        

        while(st.size()>=2){        

            char temp = st.pop();

            if(temp==st.peek()){

                count++;

            }

            else{

                count+=2;

            }

            st.pop();

        }    

        return count;
    }
}