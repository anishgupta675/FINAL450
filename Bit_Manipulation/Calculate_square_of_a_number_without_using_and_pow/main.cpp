// Square of a number using bitwise operators
#include <bits/stdc++.h>
using namespace std;
 
int square(int n)
{
    if(!n) return 0;
    if(n % 2) return (square(n >> 1) << 2) + ((n >> 1) << 2) + 1;
    return square(n >> 1) << 2;
}
 
// Driver Code
int main()
{
    // Function calls
    for (int n = 1; n <= 5; n++)
        cout << "n = " << n << ", n^2 = " << square(n)
             << endl;
    return 0;
}