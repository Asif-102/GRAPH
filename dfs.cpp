#include "bits/stdc++.h"
using namespace std;

vector<int> v[101];
bool visit[101];

void dfs(int src)
{
    cout << src << endl;
    visit[src] = true;

    for (int i = 0; i < v[src].size(); i++)
    {
        int children = v[src][i];
        if (visit[children] == false)
            dfs(children);
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
    dfs(1);
}

/*

sample input
----------------
7 7
1 2
1 6
2 3
2 4
6 4
6 7
4 5

*/