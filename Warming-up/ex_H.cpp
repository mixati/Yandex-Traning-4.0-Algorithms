#include <iostream>

using namespace std;
int main() {
    int a,b,n;
    cin >> a >> b >> n;
    int tb;
    tb = b / n;
    if (b % n != 0)
        tb++;
    if (a > tb)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
// DONE
