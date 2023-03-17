//{ Driver Code Starts
    import java.io.*;
    import java.lang.*;
    import java.util.*;
    
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
                int[] res = ob.JobScheduling(arr, n);
                System.out.println (res[0] + " " + res[1]);
            }
        }
    }
    // } Driver Code Ends
    
    
    class Solution
    {
        //Function to find the maximum profit and the number of jobs done.
        int[] JobScheduling(Job arr[], int n)
        {
            // Your code here
            Arrays.sort(arr, (a,b) -> (b.profit - a.profit));
            int max_deadline = 0;
            for(int i=0; i<n; i++) {
                if(arr[i].deadline > max_deadline)
                max_deadline = arr[i].deadline;
            }
            int doJob[] = new int[max_deadline+1];
            Arrays.fill(doJob, -1);
            int profit = 0, job_cnt = 0;
            for(int i=0; i<n; i++) {
                for(int j=arr[i].deadline; j>0; j--) {
                    if(doJob[j] == -1) {
                        doJob[j] = arr[i].id;
                        job_cnt++;
                        profit += arr[i].profit;
                        break;
                    }
                }
            }
            return new int[] { job_cnt, profit };
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