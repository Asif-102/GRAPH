// problem link -> https://cses.fi/problemset/task/1192

#include <bits/stdc++.h>
using namespace std;

int n, m;

const int N = 1010;

char grid[N][N];
int visited[N][N];

int dx[] = {0, 0, -1, +1};
int dy[] = {-1, +1, 0, 0};

bool is_inside(pair<int, int> coord){
    int x = coord.first;
    int y = coord.second;
    if(x >= 0 and x < n and y >= 0 and y < m and grid[x][y] != '#'){
        return true;
    }
    return false;
}

bool is_floor(pair<int, int> coord){
    int x = coord.first;
    int y = coord.second;
    if(grid[x][y] == '.'){
        return true;
    }
    return false;
}

void bfs(pair<int, int> src) {
    queue<pair<int, int>> q;
    q.push(src);
    visited[src.first][src.second] = 1;
    while (!q.empty()) {
        pair<int, int> head = q.front();
        q.pop();
        int x = head.first;
        int y = head.second;
        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(is_inside({new_x, new_y}) and visited[new_x][new_y] == 0 and is_floor({new_x, new_y})){
                visited[new_x][new_y] = 1;
                q.push({new_x, new_y});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for (int j = 0; j <= m; j++) {
            grid[i][j] = input[j];
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.' and visited[i][j] == 0){
                bfs({i, j});
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}