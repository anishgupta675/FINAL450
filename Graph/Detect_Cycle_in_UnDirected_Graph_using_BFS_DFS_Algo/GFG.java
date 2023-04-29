//{ Driver Code Starts
    import java.util.*;
    import java.lang.*;
    import java.io.*;
    class GFG {
        public static void main(String[] args) throws IOException {
            BufferedReader br =
                new BufferedReader(new InputStreamReader(System.in));
            int T = Integer.parseInt(br.readLine().trim());
            while (T-- > 0) {
                String[] s = br.readLine().trim().split(" ");
                int V = Integer.parseInt(s[0]);
                int E = Integer.parseInt(s[1]);
                ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
                for (int i = 0; i < V; i++) adj.add(i, new ArrayList<Integer>());
                for (int i = 0; i < E; i++) {
                    String[] S = br.readLine().trim().split(" ");
                    int u = Integer.parseInt(S[0]);
                    int v = Integer.parseInt(S[1]);
                    adj.get(u).add(v);
                    adj.get(v).add(u);
                }
                Solution obj = new Solution();
                boolean ans = obj.isCycle(V, adj);
                if (ans)
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
                    if(rank[xset] < rank[yset]) parent[xset] = yset;
                    else parent[yset] = xset;
                }
                if(rank[xset] == rank[yset]) rank[xset]++;
                return true;
            }
            return false;
        }
    }
    
    class Solution {
        // Function to detect cycle in an undirected graph.
        public boolean isCycle(int V, ArrayList<ArrayList<Integer>> adj) {
            // Code here
            return false;
        }
    }