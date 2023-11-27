#include <iostream>
#include <vector>

using namespace std;
int main() {
    
    unsigned long long p = 1000000007;
    int n, m;
    cin >> n >> m;
    unsigned long long x_ = m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // if (n % 2 == 1) {
    //     cout << n << endl;
    //     return 0;
    // }
    vector<unsigned long long> x(n+1);
    vector<unsigned long long> h(n+1);
    vector<unsigned long long> h_inv(n+1);
    x[0] = 1;
    h[0] = 0;
    h_inv[0] = 0;
    // S = ' ' + S;
    for(int i = 1; i < n+1; i++) {
        h[i] = (h[i-1] * x_ + (a[i-1])) % p;
        h_inv[i] = (h_inv[i-1] * x_ +(a[n-i])) % p;
        x[i] = (x[i-1] * x_) % p;
        // cout << h[i] << ' ' << h_inv[i] << endl;
    }
    // cout << endl;
    if (n % 2 == 0) {
        for (int i = n/2; i <= n; i++) {
            // cout << (h[n - i])  << ' ' << (h_inv[i]) - h_inv[(i-n/2)*2]*x[(n-i)] << endl;
        
            if ((h[n-i] + h_inv[(i-n/2)*2]*x[n-i])%p == h_inv[i])
                cout << i << ' ';
        }
    }
    else {
        for (int i = n/2+1; i <= n; i++) {
            // cout << (h[n - i])  << ' ' << (h_inv[i]) << ' ' << h_inv[(i-1-n/2)*2+1] * x[(n-i)] << endl;
        
            if ((h[n-i] + h_inv[(i-1-n/2)*2+1]*x[(n-i)])%p == h_inv[i])
                cout << i << ' ';
        }
    }
    cout << endl;
    return 0;
}

// cout << (h[a+len]-h[a]*x[len])%p << ' ' << (h[b+len]-h[b]*x[len])%p << endl;
