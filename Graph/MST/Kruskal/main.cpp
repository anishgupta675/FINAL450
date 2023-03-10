bool checkSpanningTree(vector<pair<int, int>> &a);

pair<int, int> kruskal(vector<pair<int, int>> &a);

vector<pair<int, int>> generic_mst() {
    vector<pair<int, int>> a;
    while(!checkSpanningTree(a)) {
        pair<int, int> edge = findSafeEdge(a);
        a.push_back(edge);
    }
    return a;
}