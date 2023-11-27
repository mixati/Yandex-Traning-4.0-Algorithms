#include <iostream>
#include <string>
#include <vector>
// #define x_ 257
// #define p 1000000007 
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
        h[i] = (h[i-1] * x_ + (S[i]-96)) % p;
        x[i] = (x[i-1] * x_) % p;
    }
    // cout << h[ss-1] << ' ' << x[ss-1] << endl; //
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int len, a, b;
        cin >> len >> a >> b;
        // for (int j = 0; j < len; j++) {
        //     if (S[a+j] != S[b+j]) {
        //         cout << "no\n";
        //         break;
        //     }
        //     else if (j+1 == len)
        //         cout << "yes\n";
        // }
        if ((h[a+len]+h[b]*x[len])%p == (h[b+len]+h[a]*x[len])%p)
            cout << "yes\n";
        else
            cout << "no\n";
        // cout << (h[a+len]-h[a]*x[len])%p << ' ' << (h[b+len]-h[b]*x[len])%p << endl; //
    }
}
// DONE
