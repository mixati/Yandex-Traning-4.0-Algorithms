#include <iostream>
#include <vector>

using namespace std;

int f_min(int a, int b, int c) {
    if (a <= b && a <= c)
        return a;
    else if (b <= a && b <= c)
        return b;
    else
        return c;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    int max = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (i > 0 && j > 0)
                arr[i][j] *= (f_min(arr[i-1][j-1],arr[i][j-1],arr[i-1][j]) + 1);
            if (arr[i][j] > max)
                max = arr[i][j];
        }
    }
    
    // cout << endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << max << endl;

    return 0;
}
// DONE
