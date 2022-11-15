//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
class GfG
{
    public static void main(String args[])throws IOException
        {
            BufferedReader br = new BufferedReader( new InputStreamReader(System.in));
            int t = Integer.parseInt(br.readLine());
            while(t-->0)
                {
                    String arr[] = br.readLine().split(" ");
                    String A = arr[0];
                    String B = arr[1];
                    Solution obj = new Solution();
                    System.out.println(obj.transform (A, B));
                }
        }
}
// } Driver Code Ends


//User function Template for Java

class Solution
{
    int transform (String A, String B)
    {
        // code here
        if(A.length()!=B.length()){

           return -1;

       }

       

       int countA=0;

       int countB=0;

       

       for(int i=0;i<A.length();i++){

           countA += A.charAt(i);

           countB += B.charAt(i);

       }

       

       if(countA!=countB){

           return -1;

       }

       

       HashSet<Character> hs=new HashSet<>();

       for(int i=0;i<A.length();i++){

           hs.add(A.charAt(i));

       }

       for(int i=0;i<A.length();i++){

          if(hs.contains(B.charAt(i))){

              

          } else{

              return -1;

          }

       }

       

       

       int m =A.length()-1;

       int n =B.length()-1;

       

       int cnt=0;

       

       while(m>=0){

           if(A.charAt(m)==B.charAt(n)){

               m--;

               n--;

           }else{

               cnt++;

               m--;

           }

           

           

       }

       

       return cnt;
    }
}