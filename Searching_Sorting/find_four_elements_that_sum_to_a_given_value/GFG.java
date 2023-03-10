package Searching_Sorting.find_four_elements_that_sum_to_a_given_value;

//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());

        while (tc-- > 0) {
            String[] nk = br.readLine().trim().split(" ");
            int n = Integer.parseInt(nk[0]);
            int k = Integer.parseInt(nk[1]);

            String[] str = br.readLine().trim().split(" ");
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(str[i]);
            }

            Solution sln = new Solution();
            ArrayList<ArrayList<Integer>> ans = sln.fourSum(a, k);
            for (ArrayList<Integer> v : ans) {
                for (int u : v) {
                    System.out.print(u + " ");
                }
                System.out.print("$");
            }
            if (ans.isEmpty()) {
                System.out.print(-1);
            }
            System.out.println();
        }
    }
}
// } Driver Code Ends


// User function Template for Java

// arr[] : int input array of integers
// k : the quadruple sum required

class Solution {
    public ArrayList<ArrayList<Integer>> fourSum(int[] arr, int k) {
        // code here
        ArrayList<ArrayList<Integer>>al=new ArrayList<>();

        if(arr==null || arr.length==0) return al;

        Arrays.sort(arr);

        int n=arr.length;

        for(int i=0;i<n;i++){

            for(int j=i+1;j<n;j++){

                

                int target=k-arr[i]-arr[j];

                

                int left=j+1;

                int right=n-1;

                

                while(left<right){

                    

                    if(target==arr[left]+arr[right]){

                        ArrayList<Integer>quad=new ArrayList<>();

                        quad.add(arr[i]);

                        quad.add(arr[j]);

                        quad.add(arr[left]);

                        quad.add(arr[right]);

                        al.add(quad);

                        

                        while(left<right && arr[left]==quad.get(2)) left++;

                        while(left<right && arr[right]==quad.get(3)) right--;

                        

                    }else if(target<arr[left]+arr[right]){

                        right--;

                    }else if(target>arr[left]+arr[right]){

                        left++;

                    }

                    

                    

                }

                

                while(j+1<n && arr[j]==arr[j+1]) j++;

            }

            while(i+1<n && arr[i]==arr[i+1]) i++;

        }

        

        return al;
    }
}