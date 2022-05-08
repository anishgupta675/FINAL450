#include <bits/stdc++.h>
using namespace std;

int *X = nullptr, *Y = nullptr;

// method returns minimum cost to break board into
// m*n squares
int minimumCostOfBreaking(int X[], int Y[], int m, int n)
{
    int res = 0;
  
    //  sort the horizontal cost in reverse order
    sort(X, X + m, greater<int>());
  
    //  sort the vertical cost in reverse order
    sort(Y, Y + n, greater<int>());
  
    //  initialize current width as 1
    int hzntl = 1, vert = 1;
  
    //  loop until one or both cost array are processed
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (X[i] > Y[j])
        {
            res += X[i] * vert;
  
            //  increase current horizontal part count by 1
            hzntl++;
            i++;
        }
        else
        {
            res += Y[j] * hzntl;
  
            //  increase current vertical part count by 1
            vert++;
            j++;
        }
    }
  
    // loop for horizontal array, if remains
    int total = 0;
    while (i < m)
        total += X[i++];
    res += total * vert;
  
    // loop for vertical array, if remains
    total = 0;
    while (j < n)
        total += Y[j++];
    res += total * hzntl;
  
    return res;
}

int main() {
    int m, n;
    cin >> m >> n;
    X = (int *)malloc((m - 1) * sizeof(int));
    for(int i = 0; i < m - 1; i++)
        cin >> X[i];
    Y = (int *)malloc((n - 1) * sizeof(int));
    for(int i = 0; i < n - 1; i++)
        cin >> Y[i];
    cout << minimumCostOfBreaking(X, Y, m - 1, n - 1);
    free(Y); free(X);
    return 0;
}