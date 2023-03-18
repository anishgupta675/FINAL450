//{ Driver Code Starts
    import java.io.*;
    import java.util.Arrays;
    import java.util.Comparator;
    
    class Job {
        int id, profit, deadline;
        Job(int x, int y, int z){
            this.id = x;
            this.deadline = y;
            this.profit = z; 
        }
    }
    
    class GfG {
        public static void main(String[] args) throws IOException{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            
            //testcases
            int t = Integer.parseInt(br.readLine().trim());
            while(t-->0){
                String inputLine[] = br.readLine().trim().split(" ");
                
                //size of array
                int n = Integer.parseInt(inputLine[0]);
                Job[] arr = new Job[n];
                inputLine = br.readLine().trim().split(" ");
                
                //adding id, deadline, profit
                for(int i=0, k=0; i<n; i++){
                    arr[i] = new Job(Integer.parseInt(inputLine[k++]), Integer.parseInt(inputLine[k++]), Integer.parseInt(inputLine[k++]));
                }
                
                Solution ob = new Solution();
                
                //function call
                /*
                int[] res = ob.JobScheduling(arr, n);
                System.out.println (res[0] + " " + res[1]);
                */
                System.out.println(ob.JobScheduling(arr, n));
            }
        }
    }
    // } Driver Code Ends
    
    
    class Solution
    {

        private int delayConflict(Job[] arr, int n) {
            for(int i = arr.length - 1; i >= 0; i--) if(arr[i].deadline <= arr[n].deadline - 1) return i;
            return -1;
        }

        private int maximizeProfit(Job[] arr, int n) {
            if(n == 1) return arr[0].profit;
            int incl_profit = arr[n - 1].profit;
            int i = delayConflict(arr, n - 1);
            if(i != -1) incl_profit+= maximizeProfit(arr, i + 1);
            int excl_profit = maximizeProfit(arr, n - 1);
            return Math.max(incl_profit, excl_profit);
        }

        //Function to find the maximum profit and the number of jobs done.
        int JobScheduling(Job arr[], int n)
        {
            // Your code here
            Arrays.sort(arr, new Comparator<Job>() {
                public int compare(Job j1, Job j2) { return j1.deadline - j2.deadline; }
            });
            return maximizeProfit(arr, n);
        }
    }
    
    /*
    class Job {
        int id, profit, deadline;
        Job(int x, int y, int z){
            this.id = x;
            this.deadline = y;
            this.profit = z; 
        }
    }
    */