
#include <bits/stdc++.h>
using namespace std;

#define MAX 10000

const int INF = 1e7;

int dis[MAX][MAX];
int Next[MAX][MAX];


void floydWarshall(int V,vector<vector<int> >& graph)
{
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dis[i][j] = graph[i][j];
            if (graph[i][j] == INF)
                Next[i][j] = -1;
            else
                Next[i][j] = j;
        }
    }
      for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {


                if (dis[i][k] == INF
                    || dis[k][j] == INF)
                    continue;

                if (dis[i][j] > dis[i][k]
                                    + dis[k][j]) {
                    dis[i][j] = dis[i][k]
                                + dis[k][j];
                    Next[i][j] = Next[i][k];
                }
            }
        }
    }
}


vector<int> constructPath(int u,int v)
{

    if (Next[u][v] == -1)
        return {};

    vector<int> path = { u };
    while (u != v) {
        u = Next[u][v];
        path.push_back(u);
    }
    return path;
}





void printPath(vector<int>& path)
{
    int n = path.size();
    for (int i = 0; i < n - 1; i++)
        cout << path[i] << " -> ";
    cout << path[n - 1] << endl;
}


int main()
{

    int V = 4;
    vector<vector<int> > graph
        = { { 0, 3, INF, 7 },
            { 8, 0, 2, INF },
            { 5, INF, 0, 1 },
            { 2, INF, INF, 0 } };


    floydWarshall(V, graph);
    vector<int> path;


    int u, v;
     cout << "Enter source and destination(u,v):   " ;
    cin >> u >> v;

    cout << "Shortest path: ";

    path = constructPath(u, v);
    printPath(path);

    return 0;

}
