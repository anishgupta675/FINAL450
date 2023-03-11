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
            int k = Integer.parseInt(stt.nextToken());
            int a[] = new int[(int)(n)];
            int b[] = new int[(int)(m)];
            
            
            String inputLine[] = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(inputLine[i]);
            }
            String inputLine1[] = br.readLine().trim().split(" ");
            for (int i = 0; i < m; i++) {
                b[i] = Integer.parseInt(inputLine1[i]);
            }
            
            
            Solution obj = new Solution();
            System.out.println(obj.kthElement( a, b, n, m, k));
            
        }
	}
}

// } Driver Code Ends


//User function Template for Java


class Solution {
    public long kthElement( int arr1[], int arr2[], int n, int m, int k) {
        if(k < 1 || k > (m + n)) return -1;
        if(n > m) return kthElement(arr2, arr1, m, n, k);
        if(n == 0) return arr2[k - 1];
        if(k == 1) return Math.max(arr1[0], arr2[0]);
        int i = Math.min(n, k / 2), j = Math.min(m, k / 2);
        if(arr1[i - 1] > arr2[j - 1]) {
            int[] temp = Arrays.copyOfRange(arr2, j, m);
            return kthElement(arr1, temp, n, m - j, k - j);
        }
        int[] temp = Arrays.copyOfRange(arr1, i, n);
        return kthElement(temp, arr2, n - i, m, k - i);
    }
}