#include <iostream>
#include <queue>

#define N 10
using namespace std;

bool bipartite(int graph[][N], int src, int n)
{
    int color[N];

    for (int i = 0; i < n; ++i)
        color[i] = -1;
 
    color[src] = 1;
 
    queue <int> q;
    q.push(src);
 
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
 
        if (graph[u][u] == 1)
        return false;
 
        for (int v = 0; v < n; ++v)
        {
            if (graph[u][v] && color[v] == -1)
            {
                color[v] = 1 - color[u];
                q.push(v);
            }
 
            else if (graph[u][v] && color[v] == color[u])
                return false;
        }
    }
 
    return true;
}

int main()
{
    int n, graph[N][N];
    bool fl;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Input adjacency matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> graph[i][j];
    }
 
    fl = bipartite(graph, 0, n);
    
    if(fl) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}