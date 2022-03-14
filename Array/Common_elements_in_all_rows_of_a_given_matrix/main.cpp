#include <bits/stdc++.h>

// Specify number of rows and columns
#define M 4
#define N 5

using namespace std;

// prints common element in all rows of matrix
void printCommonElements(int **mat)
{
    unordered_map<int, int> mp;

    // initialize 1st row elements with value 1
    for (int j = 0; j < N; j++)
        mp[mat[0][j]] = 1;

    // traverse the matrix
    for (int i = 1; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // If element is present in the map and
            // is not duplicated in current row.
            if (mp[mat[i][j]] == i)
            {
               // we increment count of the element
               // in map by 1
                mp[mat[i][j]] = i + 1;

                // If this is last row
                if (i==M-1 && mp[mat[i][j]]==M)
                  cout << mat[i][j] << " ";
            }
        }
    }
}

int main() {
    int *mat[M];
    for(int i = 0; i < M; i++) {
        mat[i] = (int *)malloc(N * sizeof(int));
        for(int j = 0; j < N; j++)
            cin >> mat[i][j];
    }
    printCommonElements(mat);
    return 0;
}
