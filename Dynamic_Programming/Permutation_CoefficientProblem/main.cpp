#include <iostream>
using namespace std;
 
int PermutationCoeff(int n, int k)
{
    int P = 1;
 
    // Compute n*(n-1)*(n-2)....(n-k+1)
    for (int i = 0; i < k; i++)
        P *= (n-i) ;
 
    return P;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << PermutationCoeff(n, k) << endl;
    return 0;
}