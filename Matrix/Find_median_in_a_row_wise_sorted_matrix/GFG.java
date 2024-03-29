//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;


class GFG
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            String S[] = read.readLine().split(" ");
            int R = Integer.parseInt(S[0]);
            int C = Integer.parseInt(S[1]);
            int matrix[][] = new int[R][C];
            int c = 0;
            for(int i = 0; i < R; i++){
                String line[]=read.readLine().trim().split(" ");
                for(int j = 0; j < C; j++){
                    matrix[i][j] = Integer.parseInt(line[j]);
                }
            }
            Solution ob = new Solution();
            int ans = ob.median(matrix, R, C);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution {
    int median(int m[][], int r, int c) {
        // code here        
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
 
        for (int i = 0; i < r; i++) {
 
            
            if (m[i][0] < min)
                min = m[i][0];
 
            
            if (m[i][m[i].length - 1] > max)
                max = m[i][m[i].length - 1];
        }
 
        int desired = (r * c + 1) / 2;
        while (min < max) {
            int mid = min + (max - min) / 2;
            int place = 0;
            int get = 0;
 
            
            for (int i = 0; i < r; ++i) {
 
                get = Arrays.binarySearch(m[i], mid);
 
                
                if (get < 0)
                    get = Math.abs(get) - 1;
 
                
                else {
                    while (get < m[i].length
                           && m[i][get] == mid)
                        get += 1;
                }
 
                place = place + get;
            }
 
            if (place < desired)
                min = mid + 1;
            else
                max = mid;
        }
        return min;
    }
}