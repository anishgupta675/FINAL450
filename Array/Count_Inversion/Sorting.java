//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.lang.*;

class Sorting
{
    public static void main (String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        long t = sc.nextLong();
        
        while(t-- > 0)
        {
            long n = sc.nextLong();
            long arr[] = new long[(int)n];
            
            for(long i = 0; i < n; i++)
             arr[(int)i] = sc.nextLong();
             
            System.out.println(new Solution().inversionCount(arr, n));
            
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution
{
    static long merge(long[] arr, int l, int m, int r) {
        int i = 0, j = 0, k = l, swaps = 0;
        long[] L = new long[(m + 1) - l];
        long[] R = new long[r - m];
        for(i = 0; i < L.length; i++)
            L[i] = arr[l + i];
        for(j = 0; j < R.length; j++)
            R[j] = arr[(m + 1) + j];
        i = 0;
        j = 0;
        k = l;
        while(i < L.length && j < R.length) {
            if(L[i] <= R[j]) arr[k++] = L[i++];
            else {
                arr[k++] = R[j++];
                swaps = (m + 1) - (l + i);
            }
        }
        while(i < L.length) arr[k++] = L[i++];
        while(j < R.length) arr[k++] = R[j++];
        return swaps;
    }
    static long mergeSort(long[] arr, int l, int r) {
        long count = 0;
        if(l <= r) {
            int m = (l + r) / 2;
            count+= mergeSort(arr, l, m);
            count+= mergeSort(arr, m + 1, r);
            count+= merge(arr, l, m, r);
        }
        return count;
    }
    // arr[]: Input Array
    // N : Size of the Array arr[]
    //Function to count inversions in the array.
    static long inversionCount(long arr[], long N)
    {
        // Your Code Here
        return mergeSort(arr, 0, (int)N - 1);
    }
}