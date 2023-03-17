import java.util.Scanner;

class Solution {

    private static final Scanner sc = new Scanner(System.in);

    private static int knapSack(int n, int m1, int p1, int m2, int p2) {
        int min_price = 0;
        while(n > 0) {
            if(m1 == n && m2 == n) {
                n = 0;
                min_price+= Math.min(p1, p2);
                break;
            }
            if(m1 == n) {
                n = 0;
                min_price+= p1;
                break;
            }
            if(m2 == n) {
                n = 0;
                min_price+= p2;
                break;
            }
            if(p1 <= p2) {
                min_price+= p1;
                n-= m1;
            } else {
                min_price+= p2;
                n-= m2;
            }
        }
        return (n == 0) ? min_price : -1;
    }

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt(), m1 = sc.nextInt(), p1 = sc.nextInt(), m2 = sc.nextInt(), p2 = sc.nextInt();
        System.out.println(knapSack(n, m1, p1, m2, p2));
    }
}