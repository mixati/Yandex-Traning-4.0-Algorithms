#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Initial array:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i != n-1)
            cout << ", ";
        else
            cout << "\n**********\n";
    }

    int m = a[0].size();
    vector<string> temp(n);
    for (int i = 1; m - i >= 0; i++) {
        cout << "Phase " << i << endl;
        int p = 0;
        for (int j = 0; j < 10; j++) {
            cout << "Bucket " << j << ": ";
            bool flag = false;
            for (int k = 0; k < n; k++) {
                if (a[k][m-i] == (char)(j+48)) {
                    temp[p] = a[k];
                    p++;
                    if (flag == false) {
                        flag = true;
                        cout << a[k];
                    }
                    else
                        cout << ", " << a[k];
                }
            }
            if (flag == false)
                cout << "empty";
            cout << endl;
        }
        a = temp;
        cout << "**********\n";
    }

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) {
        if (i != n-1)
            cout << a[i] << ", ";
        else
            cout << a[i] << endl;
    }
    return 0;
}
// DONE
