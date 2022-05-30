#include<bits/stdc++.h>
using namespace std;
 
// iPair ==>  Integer Pair
typedef pair<int, int> iPair;
 
// This class represents a dipathted graph using
// adjacency list representation
class Graph
{
    int V;    // No. of vertices
 
    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    list< pair<int, int> > *adj;
    bool pathMoreThanKUtil(int src, int k, vector<bool> &path);
 
public:
    Graph(int V);  // Constructor
 
    // function to add an edge to graph
    void addEdge(int u, int v, int w);
    bool pathMoreThanK(int src, int k);
};
 
// Returns true if graph has path more than k length
bool Graph::pathMoreThanK(int src, int k)
{
    // Create a path array with nothing included
    // in path
    vector<bool> path(V, false);
 
    // Add source vertex to path
    path[src] = 1;
 
    return pathMoreThanKUtil(src, k, path);
}
 
// Prints shortest paths from src to all other vertices
bool Graph::pathMoreThanKUtil(int src, int k, vector<bool> &path)
{
    // If k is 0 or negative, return true;
    if (k <= 0)
        return true;
 
    // Get all adjacent vertices of source vertex src and
    // recursively explore all paths from src.
    list<iPair>::iterator i;
    for (i = adj[src].begin(); i != adj[src].end(); ++i)
    {
        // Get adjacent vertex and weight of edge
        int v = (*i).first;
        int w = (*i).second;
 
        // If vertex v is already there in path, then
        // there is a cycle (we ignore this edge)
        if (path[v] == true)
            continue;
 
        // If weight of is more than k, return true
        if (w >= k)
            return true;
 
        // Else add this vertex to path
        path[v] = true;
 
        // If this adjacent can provide a path longer
        // than k, return true.
        if (pathMoreThanKUtil(v, k-w, path))
            return true;
 
        // Backtrack
        path[v] = false;
    }
 
    // If no adjacent could produce longer path, return
    // false
    return false;
}
 
// Allocates memory for adjacency list
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair> [V];
}
 
// Utility function to an edge (u, v) of weight w
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

int main() {
    int V, n, u, v, w, src, k;
    cin >> V;
    Graph g(V);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    cin >> src >> k;
    g.pathMoreThanK(src, k) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}