#include <iostream>
#include <vector>

using namespace std;

int ft_partition(vector<int> &a, int l, int r) {
    int E = l, G = l, N = l;
    int pivot = (long long)(a[l] + a[r]) / 2;
    if (l >= r)
        return 0;
    while (N <= r) {
        int y;
        if ((a[N]) < pivot) {
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
    return E;
}

void ft_quicksort(vector<int> &a, int l, int r) {
    int p;
    // cout << r - l << endl;
    // for (int i = l; i <= r; i++)
    //     cout << a[i] << ' ';
    // cout << endl;
    while (r > l) {
        p = ft_partition(a, l, r);
        if ((r - l)/2 > r-p) {
            ft_quicksort(a, l, p-1);
            l = p+1;
        }
        else {
            ft_quicksort(a, p+1, r);
            r = p-1;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int r = n-1, l = 0;
    ft_quicksort(a, l, r);
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
}
// In process
