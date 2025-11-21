//dfs

#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[1001];   
bool visited[1001];

void dfs(int node) {
    visited[node] = true;
    cout << node << " ";  

    for(int next : adj[node]) {
        if(!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    int n, m;
     cout<<"Enter no. of vertices (n) and edges (m) : ";
    cin >> n >> m;  
    cout<<"enter each edge pair (u v):"<<endl;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    cout<<"enter starting node: ";
    int start;
    cin >> start; 

    dfs(start);

    return 0;
}
