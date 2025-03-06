#include <bits/stdc++.h>
using namespace std;
 
// this structure stores information
// about a particular cell i.e
// path upto that cell and cell's
// coordinates
struct info {
    vector<int> path;
    int i;
    int j;
};
 
void printAllPaths(vector<vector<int> >& maze)
{
    int n = maze.size();
    int m = maze[0].size();
 
    queue<info> q;
    // pushing top-left cell into the queue
    q.push({ { maze[0][0] }, 0, 0 });
 
    while (!q.empty()) {
        info p = q.front();
        q.pop();
 
        // if we reached the bottom-right cell
        // i.e the destination then print the path
        if (p.i == n - 1 && p.j == m - 1) {
            for (auto x : p.path)
                cout << x << " ";
 
            cout << "\n";
        }
 
        // if we are in the last row
        // then only right movement is possible
        else if (p.i == n - 1) {
            vector<int> temp = p.path;
            // updating the current path
            temp.push_back(maze[p.i][p.j + 1]);
 
            q.push({ temp, p.i, p.j + 1 });
        }
 
        // if we are in the last column
        // then only down movement is possible
        else if (p.j == m - 1) {
            vector<int> temp = p.path;
            // updating the current path
            temp.push_back(maze[p.i + 1][p.j]);
 
            q.push({ temp, p.i + 1, p.j });
        }
 
        // else both right and down movement
        // are possible
        else { // right movement
            vector<int> temp = p.path;
            // updating the current path
            temp.push_back(maze[p.i][p.j + 1]);
 
            q.push({ temp, p.i, p.j + 1 });
 
            // down movement
            temp.pop_back();
            // updating the current path
            temp.push_back(maze[p.i + 1][p.j]);
 
            q.push({ temp, p.i + 1, p.j });
        }
    }
}

int main() {
    int m, n, data;
    vector<int> path;
    vector<vector<int>> maze;
    cin >> m >> n;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> data;
            path.push_back(data);
        }
        maze.push_back(path);
    }

    printAllPaths(maze);
    return 0;
}