#include <bits/stdc++.h>
using namespace std;
 
// Returns adjacency list representation from a list
// of pairs.
vector<unordered_set<int> >
make_graph(int numTasks,
           vector<pair<int, int> >& prerequisites)
{
    vector<unordered_set<int> > graph(numTasks);
    for (auto pre : prerequisites)
        graph[pre.second].insert(pre.first);
    return graph;
}
 
// Finds in-degree of every vertex
vector<int>
compute_indegree(vector<unordered_set<int> >& graph)
{
    vector<int> degrees(graph.size(), 0);
    for (auto neighbors : graph)
        for (int neigh : neighbors)
            degrees[neigh]++;
    return degrees;
}
 
// Main function to check whether possible to finish all
// tasks or not
bool canFinish(int numTasks,
               vector<pair<int, int> >& prerequisites)
{
    vector<unordered_set<int> > graph
        = make_graph(numTasks, prerequisites);
    vector<int> degrees = compute_indegree(graph);
    for (int i = 0; i < numTasks; i++) {
        int j = 0;
        for (; j < numTasks; j++)
            if (!degrees[j])
                break;
        if (j == numTasks)
            return false;
        degrees[j] = -1;
        for (int neigh : graph[j])
            degrees[neigh]--;
    }
    return true;
}

vector<pair<int, int>> prerequisites;

int main() {
    int numTasks, first, second;
    cin >> numTasks;
    for(int i = 0; i < numTasks; i++) {
        cin >> first >> second;
        prerequisites.push_back(make_pair(first, second));
    }
    cout << canFinish(numTasks, prerequisites) << endl;
    return 0;
}