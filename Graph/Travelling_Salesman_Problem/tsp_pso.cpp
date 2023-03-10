#include<bits/stdc++.h>

class Graph {
protected:
    std::unordered_map<std::pair<int, int>, int> edges;
    std::vector<int> vertices;
    int amount_vertices;

    void swap(int *xp, int *yp) {
        int temp = *xp;
        *xp = *yp;
        *yp = temp;
    }

    template <typename T>
    bool checkAvailable(std::vector<T> list, T target) {
        for(auto i : list) if(i == target) return true;
        return false;
    }

    int getIndex(std::vector<int> list_vertices, int target) {
        for(int i = 0; i < list_vertices.size(); i++) if(list_vertices[i] == target) return i;
        return -1;
    }

    std::vector<int> getSlice(std::vector<int> &vertices, int low = 0, int high) {
        std::vector<int> res(high - low + 1);
        copy(vertices.begin() + low, vertices.begin() + high + 1, res.begin());
        return res;
    }

    std::vector<int> shuffleList(std::vector<int> &vertices) {
        for(int i = 0; i < vertices.size(); i++) swap(&vertices[i], vertices[rand() % vertices.size()]);
        return vertices;
    }
public:
    Graph() : edges(nullptr), vertices(nullptr), amount_vertices(0) {}

    Graph(std::unordered_map<std::pair<int, int>, int> &edges, std::vector<int> &vertices, int amount_vertices) : amount_vertices(amount_vertices) {
        for(auto i : edges) this.edges[i.first] = i.second;
        for(int i : vertices) this.vertices.push_back(i);
    }

    std::vector<int> getEdges() { return this.edges; }

    std::vector<int> getVertices() { return this.vertices; }

    int getAmountVertices() { return this.amount_vertices; }

    void setEdges(std::unordered_map<std::pair<int, int>, int> &edges) { for(auto i : edges) this.edges[i.first] = i.second; }

    void setVertices(std::vector<int> &vertices) { for(int i : vertices) this.vertices.push_back(i); }

    void setAmountVertices(int amount_vertices) { this.amount_vertices = amount_vertices; }

    void addEdge(int src, int dest, int cost = 0) {
        if(!existsEdge(src, dest)) {
            this.edges[make_pair(src, dest)] = cost;
            this.vertices.push_back(src);
            this.vertices.push_back(dest);
        }
    }

    bool existsEdge(int src, int dest) { return (this.edges.find(make_pair(src, dest)) == edges.end()) ? false : true; }

    void showGraph() { for(auto i : this.edges) std::cout << i.first.first << " " << i.first.second << " " << i.second << std::endl; }

    int getCostPath(std::vector<int> &path) {
        int total_cost = 0;
        for(int i = 0; i < this.amount_vertices - 1; i++) total_cost+= this.edges[make_pair(path[i], path[i + 1])];
        total_cost+= this.edges[make_pair(path[this.amount_vertices - 1], path[0])];
        return total_cost;
    }

    std::vector<std::vector<int>> getRandomPaths(int max_size) {
        std::vector<int> list_vertices(this.vertices.begin(), this.vertices.end());
        std::vector<std::vector<int>> random_paths;
        int initial_vertice = list_vertices[rand() % list_vertices.size()];
        if(!checkAvailable(list_vertices, initial_vertice)) return nullptr;
        list_vertices.erase(list_vertices.begin() + getIndex(list_vertices, initial_vertice));
        list_vertices.push_back(initial_vertice);
        for(int i = 0; i < max_size; i++) {
            std::vector<int> list_temp = getSlice(list_vertices, 1, list_vertices.size());
            list_temp = shuffleList(list_temp);
            list_temp.push_back(initial_vertice);
            if(!checkAvailable(random_paths, list_temp)) random_paths.push_back(list_temp);
        }
        return random_paths;
    }
};

class CompleteGraph : public Graph {
public:
    void generateGraph() {
        for(int i = 0; i < super.amount_vertices; i++) {
            for(int j = 0; j < super.amount_vertices; j++) {
                if(i != j) {
                    wt = (1 + (rand() % 11)) % 11;
                    super.addEdge(i, j, wt);
                }
            }
        }
    }
}