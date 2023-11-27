#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ft_min(int a, int b) {
    return a < b ? a : b;
}

int pal_d1(string s) {
    int n = s.length();
    vector<int> d1 (n);
    int l=0, r=-1, res = 0;
    for (int i=0; i<n; ++i) {
        int k = i>r ? 1 : ft_min(d1[l+r-i], r-i+1);
        while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
        d1[i] = k;
        res += d1[i];
        if (i+k-1 > r)
            l = i-k+1,  r = i+k-1;
    }
    return res;
}


int pal_d2(string s) {
    int n = s.length();
    vector<int> d2 (n);
    int l=0, r=-1, res = 0;
    for (int i=0; i<n; ++i) {
        int k = i>r ? 0 : ft_min (d2[l+r-i+1], r-i+1);
        while (i+k < n && i-k-1 >= 0 && s[i+k] == s[i-k-1])  ++k;
        d2[i] = k;
        res += d2[i];
        if (i+k-1 > r)
            l = i-k,  r = i+k-1;
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    int n = s.length();
    // vector<int> d1(n);
    // vector<int> d2(n);
    // d2 = pal_d2(s);
    //     d1 = pal_d1(s);
    cout << pal_d1(s) + pal_d2(s);
    // for (int i = 0; i < n; i++)
    //     cout << d1[i] << ' ';
    // cout << endl;
    // for (int i = 0; i < n; i++)
    //     cout << d2[i] << ' ';
    cout << endl;
    return 0;
}
