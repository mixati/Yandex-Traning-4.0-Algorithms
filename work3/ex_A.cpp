#include <iostream>
#include <vector>
#include <climits>
#include <stack>


using namespace std;

void Dijkstra(vector<vector<int>> &GR, int V, int st, int fin)
{
    int distance[V], count, index, i, u, m=st+1;
    bool visited[V];
    int prev[V];
    prev[st] = -1;
    for (i=0; i<V; i++) {
        distance[i]=INT_MAX; visited[i]=false;
    }
    distance[st]=0;
    for (count=0; count<V-1; count++) {
        int min=INT_MAX;
        for (i=0; i<V; i++)
            if (!visited[i] && distance[i]<=min) {
                min=distance[i];
                index=i;
            }
        u=index;
        visited[u]=true;
        for (i=0; i<V; i++)
            if (!visited[i] && GR[u][i] && distance[u]!=INT_MAX &&
            distance[u]+GR[u][i]<distance[i]) {
                distance[i]=distance[u]+GR[u][i];
                prev[i] = u;
            }
    }
    // cout<<"Стоимость пути из начальной вершины до остальных:\t\n";
    // for (i=0; i<V; i++) if (distance[i]!=INT_MAX)
    //     cout<<m<<" > "<<i+1<<" = "<<distance[i]<<endl;
    // else cout<<m<<" > "<<i+1<<" = "<<"маршрут недоступен"<<endl;
    if (distance[fin] != INT_MAX) {
        cout << distance[fin] << endl;
        // int i = fin;
        // stack<int> stack;
        // while (i != -1) {
        //     // cout << i+1 << ' ';
        //     // fin = prev[fin];
        //     stack.push(i+1);
        //     i = prev[i];
        // }
        // while(!stack.empty()) {
        //     cout << stack.top() << ' ';
        //     stack.pop();
        // }
        // cout << endl;
    }
    else
        cout << -1 << endl;
}

int main() {
    int n, s, f;
    cin >> n >> s >> f;
    vector<vector<int>> a(n+1, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) { 
            cin >> a[i][j];
            if (a[i][j] == -1)
                a[i][j] = 0;
        }

    // for (short i = 0; i <= n; i++) {
    //     for (short j = 0; j <= n; j++)
    //         cout << a[i][j] << ' ';
    //     cout << endl;
    // }

    // vector<bool> visited(n, false);
    // vector<int> dist(n, INT_MAX);
    // dist[s] = 0;
    // for (int i = 1; i <= n; i++) {
    // }
    Dijkstra(a, n, s-1, f-1);

    return 0;
}

// DONE
