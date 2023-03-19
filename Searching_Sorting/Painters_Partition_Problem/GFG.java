//{ Driver Code Starts
//Initial Template for Java

/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;
class GFG {
	public static void main (String[] args) {
		Scanner sc=new Scanner(System.in);
		
		int t=sc.nextInt();
		
		while(t-->0)
		{
		    int n=sc.nextInt();
		    int a[]=new int[n];
		    
		    for(int i=0;i<n;i++)
		    {
		        a[i]=sc.nextInt();
		    }
		    int m=sc.nextInt();
		    Solution ob = new Solution();
		    System.out.println(ob.findPages(a,n,m));
		}
	}
}
// } Driver Code Ends


//User function Template for Java

class Solution 
{
    private static int res = 0;
    private static int getSum(int[] a) {
        int sum = 0;
        for(int i : a) sum+= i;
        return sum;
    }
    private static boolean checkPage(int[] a, int n, int m) {
        int i = 0, part_sum = 0, cnt = 0;
        while(i < a.length) {
            if(a[i] > n) return false;
            if((part_sum + a[i]) > n) {
                cnt++;
                part_sum = a[i];
                if(cnt >= m) return false;
            } else part_sum+= a[i];
            i++;
        }
        return true;
    }
    private static void getPage(int[] a, int low, int high, int m) {
        if(low > high) return;
        int mid = (low + high) >> 1;
        if(checkPage(a, mid, m)) {
            res = mid;
            getPage(a, low, mid - 1, m);
        } else getPage(a, mid + 1, high, m);
    }
    //Function to find minimum number of pages.
    public static int findPages(int[]A,int N,int M)
    {
        //Your code here
        getPage(A, 1, getSum(A), M);
        return res;
    }
};