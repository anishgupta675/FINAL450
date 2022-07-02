#include <bits/stdc++.h>
using namespace std;
 
class Graph {
 
    // A function used by DFS
    void DFSUtil(int v);
 
public:
    map<int, bool> visited;
    map<int, list<int> > adj;
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // prints DFS traversal of the complete graph
    void DFS();
};
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
void Graph::DFSUtil(int v)
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i);
}
 
// The function to do DFS traversal. It uses recursive
// DFSUtil()
void Graph::DFS()
{
    // Call the recursive helper function to print DFS
    // traversal starting from all vertices one by one
    for (auto i : adj)
        if (visited[i.first] == false)
            DFSUtil(i.first);
}

Graph g;

int main() {
    int n, v, w;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> v >> w;
        g.addEdge(v, w);
    }

    g.DFS();

    return 0;
}