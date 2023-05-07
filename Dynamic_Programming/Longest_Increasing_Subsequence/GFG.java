//{ Driver Code Starts
    import java.io.*;
    import java.util.*; 
    
    class GFG{
        public static void main(String args[]) throws IOException { 
            
            //taking input using Scanner class
            Scanner sc = new Scanner(System.in);
            
            //taking total testcases
            int t = sc.nextInt();
            while(t > 0){
                
                //taking size of array
                int n = sc.nextInt();
                int array[] = new int[n];
                
                //inserting elements in the array
                for (int i = 0; i < n; ++i)
                {
                    array[i] = sc.nextInt();
                }
                
                //creating an object of class Solution
                Solution ob = new Solution();
                
                //calling longestSubsequence() method of class
                //Solution
                System.out.println(ob.longestSubsequence(n,array));
                t--;
            }
        } 
    } 
    // } Driver Code Ends
    
    
    
    
    class Solution 
    {
        
        private static int lower_bound(List<Integer> a, int low, int high, int target) {
            if(low > high) return low;
            int mid = (low + high) >> 1;
            if(target <= a.get(mid)) return lower_bound(a, low, mid - 1, target);
            return lower_bound(a, mid + 1, high, target);
        }
        
        //Function to find length of longest increasing subsequence.
        static int longestSubsequence(int size, int a[])
        {
            // code here
            int count = 1;
            List<Integer> res = new ArrayList<Integer>();
            res.add(a[0]);
            for(int i = 1; i < size; i++) {
                if(a[i] > res.get(res.size() - 1)) {
                    res.add(a[i]);
                    count++;
                } else res.set(lower_bound(res, 0, res.size() - 1, a[i]), a[i]);
            }
            return res.size();
        }
    } 