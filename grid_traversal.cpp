// problem link -> https://cses.fi/problemset/task/1193

#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int maze[N][N], visited[N][N], level[N][N];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int n, m;

bool is_inside(pair<int, int> coord){
    int x = coord.first;
    int y = coord.second;
    if(x >= 0 and x < n and y >= 0 and y <= m){
        return true;
    }
    return false;
}

bool is_safe(pair<int, int> coord){
    int x = coord.first;
    int y = coord.second;
    if(maze[x][y] == -1){
        return false;
    }
    return true;
}

void BFS(pair<int, int> src){
    queue<pair<int, int>> q;
    visited[src.first][src.second] = 1;
    q.push(src);
    while(!q.empty()){
        pair<int, int> head = q.front();
        q.pop();
        int x = head.first;
        int y = head.second;
        for(int i = 0; i < 4; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            pair<int, int> adj_node = {new_x, new_y};
            if(is_inside(adj_node) and is_safe(adj_node) and visited[new_x][new_y] == 0){
                visited[new_x][new_y] = 1;
                level[new_x][new_y] = level[x][y] + 1;
                q.push(adj_node);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    pair<int, int> src, dst;
    for(int i = 0; i < n; i++){
        string input;
        cin >> input;
        for(int j = 0; j < m; j++){
            if(input[j] == '#'){
                maze[i][j] = -1;
            }else if(input[j] == 'A'){
                src = {i, j};
            }else if(input[j] == 'B'){
                dst = {i, j};
            }
        }
    }
    BFS(src);
    if(visited[dst.first][dst.second] == 0){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << level[dst.first][dst.second];
    return 0;
}