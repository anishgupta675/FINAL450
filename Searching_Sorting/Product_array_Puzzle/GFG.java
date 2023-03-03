//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*; 

class GFG{
    public static void main(String args[]) throws IOException { 
        try (Scanner sc = new Scanner(System.in)) {
            int t = sc.nextInt();
            while(t > 0){
            	int n = sc.nextInt();
            	int[] array = new int[n];
            	for (int i=0; i<n ; i++ ) {
            		array[i] = sc.nextInt();
            	}
                Solution ob = new Solution();
                long[] ans = new long[n];
                ans = ob.productExceptSelf(array, n);

               	for (int i = 0; i < n; i++) { 
            		System.out.print(ans[i]+" ");
            	} 
                System.out.println();
                t--;
            }
        }
    } 
} 
  


// } Driver Code Ends


//User function Template for Java


class Solution 
{ 
	public long[] productExceptSelf(int arr[], int n) 
	{ 
        // code here
        long[] left = new long[n];
        long[] right = new long[n];
        long[] prod = new long[n];
        left[0] = 1;
        right[n - 1] = 1;
        for(int i = 1; i < n; i++)
            left[i] = (long)arr[i - 1] * left[i - 1];
        for(int i = n - 2; i >= 0; i--)
            right[i] = (long)arr[i + 1] * right[i + 1];
        for(int i = 0; i < n; i++)
            prod[i] = left[i] * right[i];
        return prod;
	} 
} 
