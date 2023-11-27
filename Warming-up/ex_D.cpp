#include <iostream>
#include <string>
#include <map>

using namespace std;
int main() {
    string wordA, wordB;
    map<char, int> mp;
    cin >> wordA >> wordB;

    if (wordA.length() != wordB.length()) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 0; i < wordA.length(); i++)
        mp[wordA[i]]++;
    for (int i = 0; i < wordB.length(); i++) {
        mp[wordB[i]]--;
        if (mp[wordB[i]] < 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
// DONE
