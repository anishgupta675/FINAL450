#include <iostream>
using namespace std;
const int n = 4;
void print(int **mat)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}
void rotate90clockwise(int **mat)
{
    // Transpose of matrix
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            swap(mat[i][j], mat[j][i]);
    // Reverse individual rows
    for (int i = 0; i < n; i++) {
        int low = 0, high = n - 1;
        while (low < high) {
            swap(mat[i][low], mat[i][high]);
            low++;
            high--;
        }
    }
}
int main() {
    int r, c;
    cin >> r >> c;
    int *mat[n];
    for(int i = 0; i < r; i++) {
        mat[i] = (int *)malloc(n * sizeof(int));
        for(int j = 0; j < c; j++)
            cin >> mat[i][j];
    }
    rotate90clockwise(mat);
    print(mat);
    // free(mat);
    return 0;
}
