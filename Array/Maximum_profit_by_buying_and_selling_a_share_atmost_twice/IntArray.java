//{ Driver Code Starts
import java.io.*;
import java.util.*;


class IntArray
{
    public static int[] input(BufferedReader br, int n) throws IOException
    {
        String[] s = br.readLine().trim().split(" ");
        int[] a = new int[n];
        for(int i = 0; i < n; i++)
            a[i] = Integer.parseInt(s[i]);
        
        return a;
    }
    
    public static void print(int[] a)
    {
        for(int e : a)
            System.out.print(e + " ");
        System.out.println();
    }
    
    public static void print(ArrayList<Integer> a)
    {
        for(int e : a)
            System.out.print(e + " ");
        System.out.println();
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            
            int n; 
            n = Integer.parseInt(br.readLine());
            
            
            int[] price = IntArray.input(br, n);
            
            Solution obj = new Solution();
            int res = obj.maxProfit(n, price);
            
            System.out.println(res);
            
        }
    }
}

// } Driver Code Ends


class Solution {
    public static int maxProfit(int n, int[] price) {
        // code here
        int min_profit = price[0], max_profit = price[n - 1];
        int[] profit = new int[n];
        for(int i = n - 2; i >= 0; i--) {
            if(price[i] > max_profit) max_profit = price[i];
            profit[i] = Math.max(profit[i + 1], max_profit - price[i]);
        }
        for(int i = 1; i < n; i++) {
            if(price[i] < min_profit) min_profit = price[i];
            profit[i] = Math.max(profit[i - 1], profit[i] + (price[i] - min_profit));
        }
        return profit[n - 1];
    }
}
        
