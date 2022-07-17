#include<bits/stdc++.h>
 
// Number of vertices in the graph
#define V 4
 
using namespace std;
 
// function to calculate the
// number of triangles in a
// simple directed/undirected
// graph. isDirected is true if
// the graph is directed, its
// false otherwise
int countTriangle(int **graph,
                  bool isDirected)
{
    // Initialize result
    int count_Triangle = 0;
 
    // Consider every possible
    // triplet of edges in graph
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            for (int k = 0; k < V; k++)
            {
               // Check the triplet if
               // it satisfies the condition
               if (graph[i][j] && graph[j][k]
                               && graph[k][i])
                  count_Triangle++;
             }
        }
    }
 
    // If graph is directed ,
    // division is done by 3,
    // else division by 6 is done
    isDirected? count_Triangle /= 3 :
                count_Triangle /= 6;
 
    return count_Triangle;
}

int **graph = nullptr, **digraph = nullptr;

int main() {
    graph = (int **)malloc(V * sizeof(int *));
    for(int i = 0; i < V; i++) {
        graph[i] = (int *)malloc(V * sizeof(int));
        for(int j = 0; j < V; j++)
            cin >> graph[i][j];
    }
    digraph = (int **)malloc(V * sizeof(int *));
    for(int i = 0; i < V; i++) {
        digraph[i] = (int *)malloc(V * sizeof(int));
        for(int j = 0; j < V; j++)
            cin >> digraph[i][j];
    }
    cout << countTriangle(graph, false) << endl;
    cout << countTriangle(digraph, true) << endl;
    free(graph);
    free(digraph);
    return 0;
}