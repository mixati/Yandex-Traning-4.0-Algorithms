#include <iostream>

using namespace std;
int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        unsigned long long n, a, b, groups;
        cin >> n >> a >> b;
        groups = n / a;
        if (n % a <= groups*(b-a))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
// DONE
