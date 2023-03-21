//{ Driver Code Starts
// Initial Template for Java

import java.util.*;
class Rat {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int[][] a = new int[n][n];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) a[i][j] = sc.nextInt();

            Solution obj = new Solution();
            ArrayList<String> res = obj.findPath(a, n);
            Collections.sort(res);
            if (res.size() > 0) {
                for (int i = 0; i < res.size(); i++)
                    System.out.print(res.get(i) + " ");
                System.out.println();
            } else {
                System.out.println(-1);
            }
        }
    }
}

// } Driver Code Ends


// User function Template for Java

// m is the given matrix and n is the order of matrix
class Solution {
    
    private static ArrayList<String> res = new ArrayList<String>();
    
    public static void checkPath(int[][] m, int i, int j, String path) {
        if(i < 0 || i >= m.length || j < 0 || j >= m.length) return;
        if(i == m.length - 1 && j == m.length - 1) {
            res.add(path);
            return;
        }
        if(m[i][j] == 0) return;
        checkPath(m, i - 1, j, path + 'U');
        checkPath(m, i + 1, j, path + 'D');
        checkPath(m, i, j - 1, path + 'L');
        checkPath(m, i, j + 1, path + 'R');
    }
    
    public static ArrayList<String> findPath(int[][] m, int n) {
        // Your code here
        if(m[0][0] == 0 || m[n - 1][n - 1] == 0) return res;
        checkPath(m, 0, 0, "");
        return res;
    }
}