//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main(String[] args) throws IOException
	{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while(t-->0)
        {
            StringTokenizer stt = new StringTokenizer(br.readLine());
            
            int n = Integer.parseInt(stt.nextToken());
            int m = Integer.parseInt(stt.nextToken());
            // int n = Integer.parseInt(br.readLine().trim());
            int a[] = new int[n];
            String inputLine[] = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(inputLine[i]);
            }
            
            Solution obj = new Solution();
            System.out.println(obj.smallestSubWithSum(a, n, m));
        }
	}
}


// } Driver Code Ends


//User function Template for Java


class Solution {

    public static int smallestSubWithSum(int a[], int n, int x) {
        // Your code goes here 
        for(int i=1; i<n; i++){ 

            a[i] += a[i-1];

        }    

        int j=-1;

        for(int i=0; i<n; i++){

            if(a[i]>x){

                j=i;

                break;

            }    

        } 

        if(j==0) return 1;

        if(j==-1) return 0;

        

        int i=0; 

        int min=j+1;       

        while(i<j && j<n){ 

            if(a[j]-a[i]>x){

                min=Math.min(min,j-i);

                i++;

                continue;

            }

            j++;

        }

        return min;
    }
}

