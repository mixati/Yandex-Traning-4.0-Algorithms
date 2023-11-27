#include <iostream>
#include <vector>
#include <climits>
#include <queue>
// #include <fstream>
// #include <string>

// const string inp = "08.txt";

using namespace std;
int main() {

    // ifstream in("08.txt");

    int n, k;
    cin >> n >> k;
    vector<vector<pair<int,int>>> mp(n+1);
    int a, b, l;
    for (int i = 0; i < k; i++) {
        cin >> a >> b >> l;
        mp[a].push_back(make_pair(b,l));
        mp[b].push_back(make_pair(a,l));
    }

    int start, finish;
    cin >> start >> finish;
    
    // for (int i = 0; i <= n; i++) {
    //     cout << i << ": ";
    //     for (int j = 0; j < mp[i].size(); j++)
    //         cout << mp[i][j].first << ' ' << mp[i][j].second << "; ";
    //     cout<< endl;
    // }

    vector<unsigned long long> d(n+1, ULLONG_MAX), p(n+1);
    d[start] = 0;
    // vector<bool> visited(n+1, false);
    priority_queue<pair<unsigned long long,int>> q;
    q.push(make_pair(d[start],start)); 
    while(!q.empty()) {
        int v = q.top().second;
        unsigned long long current_dist = -q.top().first;
        q.pop();
        if (current_dist > d[v])
            continue;
        for (size_t i = 0; i < mp[v].size(); ++i) {
            int to = mp[v][i].first,
                len = mp[v][i].second;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push(make_pair (-d[to], to));
            }
        }
    }
    if (d[finish] == ULLONG_MAX)
        cout << -1 << endl;
    else
        cout << d[finish] << endl;
    return 0;
}

// DONE