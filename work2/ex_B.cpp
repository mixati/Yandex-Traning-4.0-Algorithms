#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
int main() {
    unsigned long long x_ = 257;
    unsigned long long p = 1000000007;
    string S;
    cin >> S;
    int ss = S.size()+1;
    vector<unsigned long long> h(ss);
    vector<unsigned long long> x(ss);
    h[0] = 0;
    x[0] = 1;
    S = ' ' + S;
    for(int i = 1; i < ss; i++) {
        h[i] = (h[i-1] * x_ + (S[i]-64)) % p;
        x[i] = (x[i-1] * x_) % p;
    }
    // cout << h[ss-1] << endl;
    for (int i = ss-2; i > 0; i--) {
        // cout << (h[i])%p << ' ' << (h[ss-1]-h[ss-i-1]*x[i])%p << endl;
        if ((h[i]+h[ss-i-1]*x[i])%p == (h[ss-1])%p) {
            cout << ss - i-1 << endl;
            return 0;
        }
    }
    cout << ss - 1 << endl;
    return 0;
}
// cout << (h[a+len]-h[a]*x[len])%p << ' ' << (h[b+len]-h[b]*x[len])%p << endl;

// DONE
