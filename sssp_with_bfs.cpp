#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int visited[N], level[N];
vector<int> adj_list[N];

void BFS(int src){
    queue<int> q;
    q.push(src);
    level[src] = 0;
    visited[src] = 1;
    while(!q.empty()){
        int head = q.front();
        q.pop();
        for(int adj_node: adj_list[head]){
            if(visited[adj_node] == 0){
                visited[adj_node] = 1;
                level[adj_node] = level[head] + 1;
                q.push(adj_node);
            }
        }
    }
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    int last_node = INT_MIN;
    for(int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
        last_node = max({last_node, u, v});
    }
    int src = 0;
    BFS(src);
    // sortest path from src node to last node
    cout << level[last_node] << '\n';
    return 0;
}

/* 
sample input
-------------------------

6 6

0 1
2 3
1 5
1 2
2 4
5 4

 */