#include<bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
private:
    unordered_map<Node *, Node *> visited;
    Node *cloneGraphDFSHelper(Node *cur) {
        if(cur == nullptr) return nullptr;
        if(visited.find(cur) != visited.end()) return visited[cur];
        Node *newNode = new Node(cur->val);
        visited[cur] = newNode;
        for(Node *n : cur->neighbors)
            newNode->neighbors.push_back(cloneGraphDFSHelper(n));
        return newNode;
    }
public:
    Node* cloneGraph(Node* node) {
        return cloneGraphDFSHelper(node);
    }
};

int main() {
    
}