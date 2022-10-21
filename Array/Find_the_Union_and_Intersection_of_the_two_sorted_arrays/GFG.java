//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
class GFG {
	public static void main (String[] args) {
	    
	    //Taking input using class Scanner
		Scanner sc=new Scanner(System.in);
		
		//Taking total count of testcases
		int t=sc.nextInt();
		sc.nextLine();
		while(t-->0)
		{
		    
		    int n,m;
		    
		    //taking size of array a
		    n=sc.nextInt();
		    
		    //taking size of array b
		    m=sc.nextInt();
		    
		    //Creating 2 array of size n and m
		    int a[]=new int[n];
		    int b[]=new int[m];
		    
		    //inserting elements to array a
		    for(int i=0;i<n;i++)
		    {
		        a[i]=sc.nextInt();
		    }
		    
		    //inserting elements to array b
		    for(int i=0;i<m;i++)
		    {
		        b[i]=sc.nextInt();
		    }
		    Solution ob=new Solution();
		    //calling doUnion method and printing the results
		    System.out.println(ob.doUnion(a,n,b,m));
		}
		
	}
}
// } Driver Code Ends


//User function Template for Java

class Solution{
    public static int doUnion(int a[], int n, int b[], int m) 
    {
        //Your code here
        int i = 0, j = 0, k = 0;
        int[] res = new int[n + m];
        Arrays.sort(a);
        Arrays.sort(b);
        while(i < n && j < m) {
            if(a[i] < b[j]) {
                if(k != 0 && res[k - 1] == a[i]) i++;
                else {
                    res[k] = a[i];
                    i++;
                    k++;
                }
            } else {
                if(k != 0 && res[k - 1] == b[j]) j++;
                else {
                    res[k] = b[j];
                    j++;
                    k++;
                }
            }
        }
        while(i < n) {
            if(k != 0 && res[k - 1] == a[i]) i++;
            else {
                res[k] = a[i];
                i++;
                k++;
            }
        }
        while(j < m) {
            if(k != 0 && res[k - 1] == b[j]) j++;
            else {
                res[k] = b[j];
                j++;
                k++;
            }
        }
        return k;
    }
}