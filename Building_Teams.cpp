// problem link -> https://cses.fi/problemset/task/1668

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m;

vector<int> adj_list[N];
int color[N];

void dfs(int src, int c) {
    color[src] = c;
    for (int adj_node : adj_list[src]) {
        if (color[src] == color[adj_node]) {
            cout << "IMPOSSIBLE\n";
            exit(0);
        } else if (color[adj_node] == 0) {
            if (color[src] == 1) {
                dfs(adj_node, 2);
            } else {
                dfs(adj_node, 1);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            dfs(i, 1);
        }
    }
    for(int i = 1; i <= n; i++){
        cout << color[i] << ' ';
    }
    return 0;
}