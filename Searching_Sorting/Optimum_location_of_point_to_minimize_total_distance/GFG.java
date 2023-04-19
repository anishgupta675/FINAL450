//{ Driver Code Starts
    import java.io.*;
    import java.util.*;
    
    
    class IntArray
    {
        public static int[] input(BufferedReader br, int n) throws IOException
        {
            String[] s = br.readLine().trim().split(" ");
            int[] a = new int[n];
            for(int i = 0; i < n; i++)
                a[i] = Integer.parseInt(s[i]);
            
            return a;
        }
        
        public static void print(int[] a)
        {
            for(int e : a)
                System.out.print(e + " ");
            System.out.println();
        }
        
        public static void print(ArrayList<Integer> a)
        {
            for(int e : a)
                System.out.print(e + " ");
            System.out.println();
        }
    }
    
    
    class IntMatrix
    {
        public static int[][] input(BufferedReader br, int n, int m) throws IOException
        {
            int[][] mat = new int[n][];
            
            for(int i = 0; i < n; i++)
            {
                String[] s = br.readLine().trim().split(" ");
                mat[i] = new int[s.length];
                for(int j = 0; j < s.length; j++)
                    mat[i][j] = Integer.parseInt(s[j]);
            }
            
            return mat;
        }
        
        public static void print(int[][] m)
        {
            for(var a : m)
            {
                for(int e : a)
                    System.out.print(e + " ");
                System.out.println();
            }
        }
        
        public static void print(ArrayList<ArrayList<Integer>> m)
        {
            for(var a : m)
            {
                for(int e : a)
                    System.out.print(e + " ");
                System.out.println();
            }
        }
    }
    
    class GFG {
        public static void main(String[] args) throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int t;
            t = Integer.parseInt(br.readLine());
            while(t-- > 0){
                
                int[] line = IntArray.input(br, 3);
                
                
                int n; 
                n = Integer.parseInt(br.readLine());
                
                
                int[][] points = IntMatrix.input(br, n, 2);
                
                Solution obj = new Solution();
                double res = obj.findOptimumCost(line, n, points);
                
                System.out.println(String.format("%.2f", res));
                
            }
        }
    }
    
    // } Driver Code Ends
    
    class Point {
        
        private int x;
        private int y;
        
        public Point() {
            this.x = 0;
            this.y = 0;
        }
        
        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
        
        public int getX() { return this.x; }
        
        public int getY() { return this.y; }
    }
    
    class Line {
        
        private int a;
        private int b;
        private int c;
        
        public Line() {
            this.a = 0;
            this.b = 0;
            this.c = 0;
        }
        
        public Line(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }
        
        public int getA() { return this.a; }
        
        public int getB() { return this.b; }
        
        public int getC() { return this.c; }
    }
    
    class Solution {
        
        private static double dist(double x, double y, Point point) { return Math.sqrt(Math.pow(x - point.getX(), 2) + Math.pow(y - point.getY(), 2)); }
        
        private static double compute(Line line, List<Point> points, int n, double x) {
            double res = 0;
            double y = -1 * (line.getC() + (line.getA() * x)) / line.getB();
            for(int i = 0; i < n; i++) res+= dist(x, y, points.get(i));
            return res;
        }
        
        private static double findOptimumCost(Line line, List<Point> points, int n) {
            double low = -1e6;
            double high = 1e6;
            while(high - low > 1e-6) {
                double mid1 = low + ((high - low) / 3);
                double mid2 = high - ((high - low) / 3);
                double dist1 = compute(line, points, n, mid1);
                double dist2 = compute(line, points, n, mid2);
                if(dist1 < dist2) high = mid2;
                else low = mid1;
            }
            return compute(line, points, n, (low + high) / 2);
        }
        
        public static double findOptimumCost(int[] line, int n, int[][] points) {
            // code here
            List<Point> p = new ArrayList<Point>();
            for(int i = 0; i < n; i++) p.add(new Point(points[i][0], points[i][1]));
            return findOptimumCost(new Line(line[0], line[1], line[2]), p, n);
        }
    }
            
    