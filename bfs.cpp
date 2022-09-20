#include "bits/stdc++.h"
using namespace std;

vector<int> v[101];
bool visit[101];

void bfs(int src)
{
    queue<pair<int, int>> q;
    q.push({src,0});
    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();

        if (visit[parent.first] == true)
            continue;
        cout << parent.first << " " << parent.second << endl;
        for (int i = 0; i < v[parent.first].size(); i++)
        {
            int children = v[parent.first][i];

            if (visit[children] == false)
            {
                q.push({children, parent.second + 1});
            }
        }
        visit[parent.first] = true;
    }
}

int main(void)
{
    int n, e;
    cin >> n >> e;

    int a, b;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(visit, false, sizeof(visit));
    cout << endl;
    bfs(1);
}

/*
n -> node
e -> edge

6 7
5 3
4 5
1 0
1 2
1 3
3 0
4 3

*/