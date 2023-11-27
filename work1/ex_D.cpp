#include <iostream>
#include <vector>

using namespace std;

void ft_merge(vector<int> &a, int l, int r) {
    if (l == r)
        return;
    int mid = (l+r) / 2;
    ft_merge(a, l, mid);
    ft_merge(a, mid+1, r);
    int i = l, j = mid+1;
    vector<int> temp(r-l+1);
    for (int step = 0; step < r-l+1; step++) {
        if ((j > r) || ((i <= mid) && (a[i] < a[j]))) {
            temp[step] = a[i];
            i++;
        }
        else {
            temp[step] = a[j];
            j++;
        }
    }
    for (int step = 0; step < r-l+1; step++)
        a[l+step] = temp[step];
    return;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n == 0)
        return 0;
    ft_merge(a, 0, n-1);
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
    return 0;
}
// DONE