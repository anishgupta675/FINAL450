//{ Driver Code Starts
import java.util.*;

class FindMinCost
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t > 0)
		{
			int n = sc.nextInt();
			int m = sc.nextInt();
			int arr[][] = new int[n][m];
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<m; j++ )
				{
					arr[i][j] = sc.nextInt();
				}
			}
			System.out.println(new Solution().maxArea(arr, n, m));
		t--;
		}
	}
}
// } Driver Code Ends


/*Complete the function given below*/
class Solution {
    static int maxHist(int R, int C, int row[])
    {
        Stack<Integer> result = new Stack<Integer>();
 
        int top_val; 
 
        int max_area = 0; 
        
 
        int area = 0; 
 
        
        int i = 0;
        while (i < C) {
            
            
            if (result.empty()
                || row[result.peek()] <= row[i])
                result.push(i++);
 
            else {
                
                
                
                
                
                
                top_val = row[result.peek()];
                result.pop();
                area = top_val * i;
 
                if (!result.empty())
                    area
                        = top_val * (i - result.peek() - 1);
                max_area = Math.max(area, max_area);
            }
        }
 
        
        
        
        while (!result.empty()) {
            top_val = row[result.peek()];
            result.pop();
            area = top_val * i;
            if (!result.empty())
                area = top_val * (i - result.peek() - 1);
 
            max_area = Math.max(area, max_area);
        }
        return max_area;
    }
    public int maxArea(int A[][], int R, int C) {
        // add code here.
        int result = maxHist(R, C, A[0]);
 
        
        
        for (int i = 1; i < R; i++) {
 
            for (int j = 0; j < C; j++)
 
                
                if (A[i][j] == 1)
                    A[i][j] += A[i - 1][j];
 
            
            
            result = Math.max(result, maxHist(R, C, A[i]));
        }
 
        return result;
    }
}