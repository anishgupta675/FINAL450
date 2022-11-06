//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0){
            int N = Integer.parseInt(in.readLine());
            String a[] = in.readLine().trim().split("\\s+");
            int arr[] = new int[N];
            for(int i = 0;i < N;i++)
                arr[i] = Integer.parseInt(a[i]);
            
            Solution ob = new Solution();
            List<Integer> ans = new ArrayList<Integer>();
            ans = ob.nextPermutation(N, arr);
            StringBuilder out = new StringBuilder();
            for(int i = 0;i < N;i++)
                out.append(ans.get(i) + " ");
            System.out.println(out);
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution{
    static List<Integer> nextPermutation(int N, int arr[]){
        // code here
        int[] arr2 = new int[N];

        arr2 = arr;

       

        int ind1 = findBreakingPt(N, arr2);

        if(ind1 == -1){

           reverse(0 ,N-1, arr2);

        }

        

        else{

            

               int ind2 = findNextHighest(ind1, N, arr2);

            

                swap(ind1, ind2, arr2);

                reverse(ind1+1, N-1,  arr2);

        }

    

        List <Integer> ans  = new ArrayList<Integer>();

        for(int i : arr2){ans.add(i);}

        return ans;
    }
    
    public static int findBreakingPt(int N, int arr[]){

        int breakingPt = -1;

        

        for(int i = N-2; i >= 0; i--){

            if(arr[i]<arr[i+1]){

                breakingPt = i;

                return i;

            }

        }

        return breakingPt;

    }
    
    public static int findNextHighest(int ind1,int N,int[] arr){

        int nextHighest = 0;

        int breakingPtValue  = arr[ind1];

        // System.out.println(breakingPtValue);

        for(int i = N-1; i >= 0; i--){

            if(arr[i]> breakingPtValue){

                return i;

            }

        }

        

        return nextHighest;

    }
    
    public static void reverse(int ind1, int ind2, int arr[]){

        int i = ind1;

        int j = ind2;

        while(i<j){

           swap(i++, j--, arr);

        }       

    }
    
    public static void swap(int ind1, int ind2, int arr[]){

        int temp = arr[ind1];

        arr[ind1] = arr[ind2];

        arr[ind2] = temp;     

    }  
}