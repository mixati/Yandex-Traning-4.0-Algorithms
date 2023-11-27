#include <iostream>
#include <vector>

using namespace std;
int main() {
    unsigned long long k, n;
    unsigned long long time = 0;
    cin >> k >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int level = n;
    unsigned long long temp_k = 0, temp_level = n;
    bool flag = false;

    while (level != -1 && a[level-1] == 0)
        level--;
    while (level != -1) {
        time += level * 2 * (a[level-1] / k);
        a[level-1] %= k;
        if (a[level-1] > 0) {
            temp_k = a[level-1];
            a[level-1] = 0;
            temp_level = level;
        }
        while (temp_k) {
            while (level != -1 && a[level-1] == 0)
                level--;
            if (level == -1) {
                flag = true;
                break;
            }
            if (a[level-1] > k-temp_k) {
                a[level-1] -= (k-temp_k);
                temp_k = 0;
                time += temp_level * 2;
            }
            else if (a[level-1] == k-temp_k) {
                temp_k = 0;
                a[level-1] = 0;
                time += temp_level * 2;
            }
            else {
                temp_k += a[level-1];
                a[level-1] = 0;
            }
        }
        if (flag == true)
            break;
        while (level != -1 && a[level-1] == 0)
            level--;
        }
    if (temp_k)
        time += temp_level * 2;

    cout << time << endl;
    return 0;
}
// DONE
