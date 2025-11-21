//bfs

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, e;
    cout<<"Enter no. of vertices (n) and edges (e) : "<<endl;
    if(!(cin >> n >> e) || n <= 0 || e < 0){
        cout << "Invalid n or e\n";
        return 1;
    }

    // use n+1 so vertices are 1..n
    vector<vector<int>> graph(n+1);
    vector<int> visited(n+1, 0);

    cout<<"enter each edge pair (u v) [1-based indices] :"<<endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        if(!(cin >> u >> v)){
            cout << "Invalid edge input\n";
            return 1;
        }
        if (u < 1 || u > n || v < 1 || v > n) {
            cout << "Edge ("<<u<<","<<v<<") out of range\n";
            return 1;
        }
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cout<<"enter the starting node (1-based): ";
    if(!(cin >> start)){
        cout << "Invalid start node\n";
        return 1;
    }
    if (start < 1 || start > n){
        cout << "Start node out of range\n";
        return 1;
    }

    queue<int> q;
    q.push(start);
    visited[start] = 1;

    cout << "BFS order: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int x : graph[node]) {
            if (!visited[x]) {
                visited[x] = 1;
                q.push(x);
            }
        }
    }
    cout << endl;

    return 0;
}
