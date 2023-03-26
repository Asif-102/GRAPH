// problem link -> https://cses.fi/problemset/task/1667/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> adj_list[N];
int visited[N], level[N];

int parent[N];

void BFS(int src){
    visited[src] = 1;
    level[src] = 1;
    parent[src] = -1;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int head = q.front();
        q.pop();
        for(int adj_node: adj_list[head]){
            if(visited[adj_node] == 0){
                parent[adj_node] = head;
                visited[adj_node] = 1;
                level[adj_node] = level[head] + 1;
                q.push(adj_node);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int src_node = 1;
    BFS(src_node);
    int dest_node = n;
    if(visited[dest_node] == 0){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << level[dest_node] << '\n';
    stack<int> path_st;
    int selected_node = dest_node;
    while(true){
        if(selected_node == -1){
            break;
        }
        path_st.push(selected_node);
        selected_node = parent[selected_node];
    }
    while(!path_st.empty()){
        cout << path_st.top() << ' ';
        path_st.pop();
    }
    return 0;
}