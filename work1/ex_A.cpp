#include <iostream>
#include <vector>

using namespace std;

int ft_partition(int pivot, vector<int> a, int l, int r) {
    int E = l, G = l, N = l;
    while (N <= r) {
        int y;
        if (a[N] < pivot) {
            y = a[N];
            a[N] = a[G];
            a[G] = a[E];
            a[E] = y;
            E++;
            G++;
        }
        else if (a[N] == pivot) {
            y = a[N];
            a[N] = a[G];
            a[G] = y;
            G++;
        }
        N++;
    }
    // for (int i = 0; i <= r; i++)
    //     cout << a[i] << ' ';
    // cout << endl;
    return E;
}

int main() {
    int n, pivot;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> pivot;
    if (n == 0) {
        cout << "0\n0\n";
        return 0;
    }
    int p = ft_partition(pivot, a, 0, n-1);
    cout << p << endl << n-p << endl;
    // for (int i = 0; i < n; i++)
    //     cout << a[i] << ' ';
    // cout << endl;
    return 0;
}
// DONE
