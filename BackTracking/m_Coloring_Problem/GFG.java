//{ Driver Code Starts
    import java.util.*;
    import java.lang.*;
    import java.io.*;
    
    class GFG {
        public static void main(String[] args) {
            Scanner scan = new Scanner(System.in);
            int tc = scan.nextInt();
    
            while (tc-- > 0) {
                int N = scan.nextInt();
                int M = scan.nextInt();
                int E = scan.nextInt();
    
                boolean graph[][] = new boolean[N][N];
    
                for (int i = 0; i < E; i++) {
                    int u = scan.nextInt() - 1;
                    int v = scan.nextInt() - 1;
                    graph[u][v] = true;
                    graph[v][u] = true;
                }
    
                System.out.println(new solve().graphColoring(graph, M, N) ? 1 : 0);
            }
        }
    }
    
    // } Driver Code Ends
    
    
    class solve {
        
        private int m;
        private int n;
        private ArrayList<Integer> vis = new ArrayList<Integer>();
        
        private boolean checkColor(boolean[][] graph, int v, int c) {
            for(int i = 0; i < n; i++) if(i != v && graph[i][v] == true && vis.get(i) == c) return false;
            return true;
        }
        
        private boolean getColor(boolean[][] graph, int v) {
            if(v == n) return true;
            for(int i = 0; i < m; i++) {
                if(checkColor(graph, v, i + 1) != true) continue;
                vis.set(v, i + 1);
                if(getColor(graph, v + 1) == true) return true;
                vis.set(v, 0);
            }
            return false;
        }
        
        // Function to determine if graph can be coloured with at most M colours
        // such
        // that no two adjacent vertices of graph are coloured with same colour.
        public boolean graphColoring(boolean graph[][], int m, int n) {
            // Your code here
            this.m = m;
            this.n = n;
            for(int i = 0; i < n; i++) vis.add(0);
            return getColor(graph, 0);
        }
    }