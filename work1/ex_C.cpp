#include <iostream>
#include <vector>

using namespace std;

void ft_merge(vector<int> &arr1, int n, vector<int> &arr2, int m, vector<int> &arr_full) {
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            arr_full[i+j] = arr1[i];
            i++;
        }
        else {
            arr_full[i+j] = arr2[j];
            j++;
        }
    }
    while (i < n) {
        arr_full[i+j] = arr1[i];
        i++;
    }
    while (j < m) {
        arr_full[i+j] = arr2[j];
        j++;
    }
}

int main() {
    int n, m;
    cin >> n;
    vector<int> arr1(n);
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    cin >> m;
    vector<int> arr2(m);
    for (int i = 0; i < m; i++)
        cin >> arr2[i];
    vector<int> arr_full(n+m);
    ft_merge(arr1, n, arr2, m, arr_full);

    for (int i = 0; i < n+m; i++)
        cout << arr_full[i] << ' ';
    cout << endl;
    return 0;
}
// DONE