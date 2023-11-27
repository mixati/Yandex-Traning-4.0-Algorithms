#include <iostream>
// #include <vector>
#include <algorithm>
#include <string>
using namespace std;



int main() {
    int n;
    cin >> n;
    string a;
    for (int i = 0; i < n; i++)
        a.push_back(i+1 +48);

    do
        cout << a << endl;
    while(next_permutation(a.begin(), a.end()));
    return 0;
}

// DONE
