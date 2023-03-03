//{ Driver Code Starts
    import java.util.*;
    import java.io.*;
    
    class GFG {
        public static void main(String[] args) throws IOException
        {
                BufferedReader br =
                new BufferedReader(new InputStreamReader(System.in));
            int t =
                Integer.parseInt(br.readLine().trim()); // Inputting the testcases
            while(t-->0)
            {
                int n = Integer.parseInt(br.readLine().trim());
                Integer arr[] = new Integer[(int)(n)];
                String inputLine[] = br.readLine().trim().split(" ");
                for (int i = 0; i < n; i++) {
                    arr[i] = Integer.parseInt(inputLine[i]);
                }
                
                Compute obj = new Compute();
                obj.sortBySetBitCount(arr, n);
                StringBuilder output = new StringBuilder();
                for(int i = 0; i < n; i++)
                output.append(arr[i] + " ");
                System.out.println(output);
                
            }
        }
    }
    
    
    // } Driver Code Ends
    
    
    //User function Template for Java
    
    
    class Compute  
    { 
        static int setBitCount(int num) {
            int count = 0;
            while(num != 0) {
                if((num & 1) != 0) count++;
                num >>= 1;
            }
            return count;
        }
        void sortBySetBitCount(Integer arr[], int n)
        { 
            // Your code goes here
            ArrayList<ArrayList<Integer>> count = new ArrayList<ArrayList<Integer>>();
            for(int i = 0; i < n; i++)
                count.add(new ArrayList<Integer>(Arrays.asList((-1) * setBitCount(arr[i]), arr[i])));
            Collections.sort(count, new Comparator<ArrayList<Integer>>() {
                @Override
                public int compare(ArrayList<Integer> o1, ArrayList<Integer> o2) {
                    return o1.get(0).compareTo(o2.get(0));
                }
            });
            for(int i = 0; i < count.size(); i++)
                arr[i] = count.get(i).get(1);
        }
    }
    