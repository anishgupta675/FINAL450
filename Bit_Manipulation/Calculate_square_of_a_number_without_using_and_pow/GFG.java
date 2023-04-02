// Square of a number using
// bitwise operators
class GFG {
    static int square(int n)
    {
        if(n == 0) return 0;
        if(n % 2 == 0) return square(n >> 1);
        return (square(n >> 1) << 2) + ((n >> 1) << 2) + 1;
    }
 
    // Driver code
    public static void main(String args[])
    {
        // Function calls
        for (int n = 1; n <= 5; n++)
            System.out.println("n = " + n
                               + " n^2 = " + square(n));
    }
}
 
// This code is contributed by Sam007