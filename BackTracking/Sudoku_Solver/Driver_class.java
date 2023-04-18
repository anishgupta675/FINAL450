//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.lang.*;

class Driver_class
{
    public static void main(String args[])
    {
        
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            int grid[][] = new int[9][9];
            for(int i = 0; i < 9; i++)
            {
                for(int j = 0; j < 9; j++)
                grid[i][j] = sc.nextInt();
            }
            
            Solution ob = new Solution();
            
            if(ob.SolveSudoku(grid) == true)
                ob.printGrid(grid);
            else
                System.out.print("NO solution exists");
            System.out.println();
            
        }
    }
}




// } Driver Code Ends


//User function Template for Java

class Solution
{
    
    private static int closestMultiple(int n, int x) {
        if(x > n) return x;
        n = n + x / 2;
        n = n - (n % x);
        return n;
    }
    
    private static int minimizeBound(int n, int x) {
        int closest_multiple = closestMultiple(n, x);
        if(closest_multiple <= n) return closest_multiple;
        return closest_multiple - x;
    }
    
    private static int maximizeBound(int n, int x) {
        int closest_multiple = closestMultiple(n, x);
        if(closest_multiple <= n) return closest_multiple + x;
        return closest_multiple;
    }
    
    private static boolean isValid(int[][] grid, int r, int c, int target) {
        for(int i = 0; i < grid.length; i++) if(grid[i][c] == target) return false;
        for(int j = 0; j < grid[r].length; j++) if(grid[r][j] == target) return false;
        for(int i = Math.abs(minimizeBound(r, 3)); i <= Math.abs(maximizeBound(r, 3)); i++) for(int j = Math.abs(minimizeBound(c, 3)); j <= Math.abs(maximizeBound(c, 3)); j++) if(grid[i][j] == target) return false;
        return true;
    }
    
    static void SolveSudoku(int[][] grid, int i, int j) {
        int ni = 0, nj = 0;
        if(j == grid[i].length) {
            ni = i + 1;
            nj = 0;
        } else {
            ni = i;
            nj = j + 1;
        }
        if(grid[i][j] != 0) SolveSudoku(grid, ni, nj);
        for(int po = 0; po <= 9; po++) {
            if(isValid(grid, i, j, po)) {
                grid[i][j] = po;
                SolveSudoku(grid, ni, nj);
                grid[i][j] = 0;
            }
        }
    }
    
    //Function to find a solved Sudoku. 
    static boolean SolveSudoku(int grid[][])
    {
        // add your code here
        SolveSudoku(grid, 0, 0);
        for(int i = 0; i < grid.length; i++) for(int j = 0; j < grid[i].length; j++) if(grid[i][j] == 0) return false;
        return true;
    }
    
    //Function to print grids of the Sudoku.
    static void printGrid (int grid[][])
    {
        // add your code here
        if(SolveSudoku(grid)) for(int i = 0; i < grid.length; i++) for(int j = 0; j < grid[i].length; j++) System.out.print(grid[i][j] + " ");
    }
}