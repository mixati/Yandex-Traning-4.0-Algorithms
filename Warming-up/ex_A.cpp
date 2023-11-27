#include <iostream>
#include <vector>

using namespace std;
int main() {
    int n, m;
    
    cin >> n >> m;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    for (int i = 0; i < m; i++) {
        int l, r;
        bool flag = false;
        
        cin >> l >> r;
        int temp = arr[l++];
        while (l <= r) {
            if (arr[l] > temp) {
                cout << arr[l] << endl;
                flag = true;
                break;
            }
            else if (arr[l] < temp) {
                cout << temp << endl;
                flag = true;
                break;
            }
            l++;
        }
        if (!flag)
            cout << "NOT FOUND" << endl;
    }
    return 0;
}
// DONE
