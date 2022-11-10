//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0)
        {
            int n = sc.nextInt();
            String arr[] = new String[n];
            for(int i = 0;i<n;i++)
                arr[i] = sc.next();
            
            Solution ob = new Solution();
            
            System.out.println(ob.secFrequent(arr, n));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution
{
    String secFrequent(String arr[], int N)
    {
        // your code here
        String ans="";

        HashMap<String,Integer> hm = new HashMap<>();

        for(int i=0; i<N; i++){

            String str = arr[i];

            hm.put(str,hm.getOrDefault(str,0)+1);

        }

        int fmax=-1, smax=-1; 

        for(String i : hm.keySet()){

            if(hm.get(i)>fmax){

                smax=fmax;

                fmax = hm.get(i);

            }

            else if(hm.get(i)>smax){

                smax=hm.get(i);

            }

        }

        for(String i : hm.keySet()){

            if(hm.get(i)==smax)

                ans = i;

        }

        return ans;
    }
}