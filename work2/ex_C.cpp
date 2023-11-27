#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ft_min(int a, int b) {
    return a < b ? a : b;
}

vector<int> z_function (string s) {
	int n = (int) s.length();
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = ft_min(r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}

int main() {
    // unsigned long long x_ = 10;
    // unsigned long long p = 1000000007;
    string s;
    cin >> s;
    int n = s.size();
    // vector<unsigned long long> h(n);
    // vector<unsigned long long> x(n);
    vector<int> z = z_function(s);
    for (int i = 0; i < n; i++) {
        cout << z[i] << ' ';
    }
    cout << endl;
    // h[0] = 0;
    // x[0] = 1;
    // s = ' ' + s;
    // for(int i = 1; i < n; i++) {
    //     h[i] = (h[i-1] * x_ + (s[i])-96) % p;
    //     x[i] = (x[i-1] * x_) % p;
    // }
    // cout << h[n-1] << endl;
    
    // cout << "0 ";
    // for (int i = 1, l=0,r=0; i < n; i++) {
    //     // for (int j = n-i-1; j >= 0; j--) {
    //     //     cout << (h[j])%p << ' ' << (h[i+j]-h[i]*x[j])%p << endl;
    //     //     if ((h[j]+h[i]*x[j])%p == (h[i+j])%p) {
    //     //         cout << j << ' ';
    //     //         break;
    //     //     }
    //     // }
    //     if (i <= r) {
    //         z[i] = ft_min(r-i+1, z[i-l]);
        
    //     }
    // }
    // cout << endl;


    return 0;
}

// cout << (h[a+len]-h[a]*x[len])%p << ' ' << (h[b+len]-h[b]*x[len])%p << endl;

// DONE