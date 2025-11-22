#include<iostream>
#include<vector>
using namespace std;


vector<int> adj[1001];
bool visited[1001];

void dfs(int node){
    visited[node] = true;
    cout<<node<<" ";

    for(int x : adj[node]){
        if(!visited[x]){
            dfs(x);
        }
    }
}

int main(){
    int m,n;
    cout<<"enter m add n :";
    cin>>m>>n;
    cout<<"each edge pair"<<endl;

    for(int i = 1; i<=m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cout<<"enter starting node: ";
    cin>> start;

    dfs(start);
    return 0;
}