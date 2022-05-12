#include <bits/stdc++.h>
using namespace std;

int **weights = nullptr;

int maxindex(int* dist, int n)
{
    int mi = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] > dist[mi])
            mi = i;
    }
    return mi;
}
 
void selectKcities(int n, int **weights, int k)
{
    int* dist = new int[n];
    vector<int> centers;
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
 
    // index of city having the
    // maximum distance to it's
    // closest center
    int max = 0;
    for (int i = 0; i < k; i++) {
        centers.push_back(max);
        for (int j = 0; j < n; j++) {
 
            // updating the distance
            // of the cities to their
            // closest centers
            dist[j] = min(dist[j], weights[max][j]);
        }
 
        // updating the index of the
        // city with the maximum
        // distance to it's closest center
        max = maxindex(dist, n);
    }
 
    // Printing the maximum distance
    // of a city to a center
    // that is our answer
    cout << endl << dist[max] << endl;
 
    // Printing the cities that
    // were chosen to be made
    // centers
    for (int i = 0; i < centers.size(); i++) {
        cout << centers[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, k;
    cin >> n;
    int **weights = (int **)malloc(n * sizeof(int *));
    for(int i = 0; i < n; i++) {
        weights[i] = (int *)malloc(n * sizeof(int));
        for(int j = 0; j < n; j++)
            cin >> weights[i][j];
    }
    cin >> k;
    selectKcities(n, weights, k);
    free(weights);
    return 0;
}