//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;
import java.lang.*;

class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0) {
            int n = Integer.parseInt(in.readLine());
            
            Solution ob = new Solution();
            ArrayList<ArrayList<Integer>> ans = ob.nQueen(n);
            if(ans.size() == 0)
                System.out.println("-1");
            else {
                for(int i = 0;i < ans.size();i++){
                    System.out.print("[");
                    for(int j = 0;j < ans.get(i).size();j++)
                        System.out.print(ans.get(i).get(j) + " ");
                    System.out.print("] ");
                }
                System.out.println();
            }
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution{
    
    private static HashMap<Integer, Boolean> rowMap = new HashMap<>();
    private static HashMap<Integer, Boolean> upperLeftDiagonalMap = new HashMap<>();
    private static HashMap<Integer, Boolean> bottomLeftDiagonalMap = new HashMap<>();
    
    private static void addBoard(char[][] board, int n, ArrayList<ArrayList<Integer>> result) {
        ArrayList<Integer> temp = new ArrayList<>();
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(board[j][i] == 'Q') temp.add(i + 1);
        result.add(temp);
    }
    
    private static boolean isSafe(char[][] board, int row, int col) {
        if(rowMap.containsKey(row)) return false;
        if(upperLeftDiagonalMap.containsKey(row - col)) return false;
        if(bottomLeftDiagonalMap.containsKey(row + col)) return false;
        return true;
    }
    
    private static void solve(char[][] board, int col, int n, ArrayList<ArrayList<Integer>> result) {
        if(col == n) {
            addBoard(board, n, result);
            return;
        }
        for(int row = 0; row < n; row++) {
            if(isSafe(board, row, col)) {
                rowMap.put(row, true);
                upperLeftDiagonalMap.put(row - col, true);
                bottomLeftDiagonalMap.put(row + col, true);
                
                board[row][col] = 'Q';
                
                solve(board, col + 1, n, result);
                
                board[row][col] = '.';
                rowMap.remove(row);
                upperLeftDiagonalMap.remove(row - col);
                bottomLeftDiagonalMap.remove(row + col);
            }
        }
    }
    
    static ArrayList<ArrayList<Integer>> nQueen(int n) {
        // code here
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        char[][] board = new char[n][n];
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) board[i][j] = '.';
        solve(board, 0, n, result);
        return result;
    }
}