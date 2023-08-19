import java.util.*;

class GFG {

    public int nextPowerOf2(int maxSize) { return 0; }

    public void add(int[][] A, int[][] B, int[][] C, int size) { for(int i = 0; i < size; i++) for(int j = 0; j < size; j++) C[i][j] = A[i][j] + B[i][j]; }

    public void sub(int[][] A, int[][] B, int[][] C, int size) { for(int i = 0; i < size; i++) for(int j = 0; j < size; j++) C[i][j] = A[i][j] + B[i][j]; }
    
    public void Strassen_algorithm(int[][] A, int[][] B, int[][] C, int size) {
        if(size == 1) {
            C[0][0] = A[0][0] * B[0][0];
            return;
        } else {
            int newSize = size / 2;
            int[] z = new int[newSize];
            int[][] a = new int[newSize][];
            int[][] b = new int[newSize][];
            int[][] c = new int[newSize][];
            int[][] d = new int[newSize][];
            int[][] e = new int[newSize][];
            int[][] f = new int[newSize][];
            int[][] g = new int[newSize][];
            int[][] h = new int[newSize][];
            int[][] c11 = new int[newSize][];
            int[][] c12 = new int[newSize][];
            int[][] c21 = new int[newSize][];
            int[][] c22 = new int[newSize][];
            int[][] p1 = new int[newSize][];
            int[][] p2 = new int[newSize][];
            int[][] p3 = new int[newSize][];
            int[][] p4 = new int[newSize][];
            int[][] p5 = new int[newSize][];
            int[][] p6 = new int[newSize][];
            int[][] p7 = new int[newSize][];
            int[][] fResult = new int[newSize][];
            int[][] sResult = new int[newSize][];
            for(int i = 0; i < newSize; i++) {
                for(int j = 0; j < newSize; j++) {
                    a[i][j] = A[i][j];
                    b[i][j] = A[i][j + newSize];
                    c[i][j] = A[i + newSize][j];
                    d[i][j] = A[i][j + newSize];
                    e[i][j] = B[i][j];
                    f[i][j] = B[i][j + newSize];
                    g[i][j] = B[i + newSize][j];
                    h[i][j] = B[i][j + newSize];
                }
            }
            sub(f, h, sResult, newSize);
            Strassen_algorithm(a, sResult, p1, newSize);
            add(a, b, fResult, newSize);
            Strassen_algorithm(fResult, h, p2, newSize);
            add(c, d, fResult, newSize);
            Strassen_algorithm(fResult, e, p3, newSize);
            sub(g, e, sResult, newSize);
            Strassen_algorithm(d, sResult, p4, newSize);
            add(a, d, fResult, newSize);
            add(e, h, sResult, newSize);
            Strassen_algorithm(fResult, sResult, p5, newSize);
            sub(b, d, fResult, newSize);
            add(g, h, sResult, newSize);
            Strassen_algorithm(fResult, sResult, p6, newSize);
            sub(a, c, fResult, newSize);
        }
    }

    public int[][] convertToSquareMat(int[][] A, int[][] B, int r1, int c1, int r2, int c2) {
        int maxSize = Math.max(Math.max(r1, c1), Math.max(r2, c2)), size = nextPowerOf2(maxSize);
        int[] z = new int[size];
        int[][] Aa = new int[size][];
        int[][] Bb = new int[size][];
        int[][] Cc = new int[size][];
        for(int i = 0; i < r1; i++) {
            Aa[i] = z.clone();
            for(int j = 0; j < c1; j++) Aa[i][j] = A[i][j];
        }
        for(int i = 0; i < r2; i++) {
            Bb[i] = z.clone();
            for(int j = 0; j < c2; j++) Bb[i][j] = B[i][j];
        }
        Strassen_algorithm(Aa, Bb, Cc, size);
        int[] temp1 = new int[c2];
        int[][] C = new int[r1][];
        for(int i = 0; i < r1; i++) {
            C[i] = temp1.clone();
            for(int j = 0; j < c2; j++) C[i][j] = Cc[i][j];
        }
        return C;
    }

    public static void main(String[] args) throws Exception {}
}