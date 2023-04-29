//{ Driver Code Starts
    import java.util.*;
    import java.io.*;
    import java.lang.*;
    
    class DriverClass {
        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
    
            while (t-- > 0) {
                ArrayList<ArrayList<Integer>> list = new ArrayList<>();
                int V = sc.nextInt();
                int E = sc.nextInt();
                for (int i = 0; i < V; i++)
                    list.add(i, new ArrayList<Integer>());
                for (int i = 0; i < E; i++) {
                    int u = sc.nextInt();
                    int v = sc.nextInt();
                    list.get(u).add(v);
                }
                if (new Solution().isCyclic(V, list) == true)
                    System.out.println("1");
                else
                    System.out.println("0");
            }
        }
    }
    // } Driver Code Ends
    
    class DSU {
        
        private int[] parent;
        private int[] rank;
        
        public DSU(int n) {
            parent = new int[n];
            rank = new int[n];
            for(int i = 0; i < n; i++) parent[i] = i;
        }

        public int find(int x) {
            if(parent[x] == x) return x;
            return find(parent[x]);
        }

        public boolean union(int x, int y) {
            int xset = find(x), yset = find(y);
            if(xset != yset) {
                if(rank[xset] != rank[yset]) {
                    if(parent[xset] < parent[yset]) parent[xset] = yset;
                    else parent[yset] = xset;
                }
                if(rank[xset] == rank[yset]) rank[xset]++;
                return true;
            }
            return false;
        }
    }
    
    /*Complete the function below*/
    
    class Solution {
        // Function to detect cycle in a directed graph.
        public boolean isCyclic(int V, ArrayList<ArrayList<Integer>> adj) {
            // code here
            return false;
        }
    }