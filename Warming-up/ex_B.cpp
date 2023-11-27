#include <iostream>

using namespace std;
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int m, n;
    n = b * d;
    m = a * d + c * b;
    int tm = m, tn = n;
    while (tm && tn) {
        if (tm > tn)
            tm = tm % tn;
        else
            tn = tn % tm;
    }
    int NOD = tm + tn;
    cout << m / NOD << ' ' << n / NOD << endl;
    
    return 0;
}
// DONE
