#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> sums(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i > 0)
            sums[i] = sums[i-1]+arr[i];
        else
            sums[i] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        int res;
        res = (arr[i] * (i+1) - sums[i]) + (sums[n-1]-sums[i] - arr[i]*(n-i-1));
        cout << res << ' ';
    }
    cout << endl;
    return 0;
}
// DONE
