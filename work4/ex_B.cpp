#include <iostream>
#include <vector>

using namespace std;

bool check(int i, int j, int k, int board[]) {
    if (k == i) return true;
    else return board[k] != j && (i - k) != (j - board[k]) && (i - k) != (board[k] - j) && check(i, j, k + 1, board);
}

int rec(int n, int i, int j, int board[]) {
    if (i == n) return 1;
    if (j < n) {
        int r = 0;
        if (check(i, j, 0, board)) {
            board[i] = j;
            r = rec(n, i + 1, 0, board);
        }
        return r + rec(n, i, j+1, board);
    }
    return 0;
}

int main() {
    int n, count = 0;
    cin >> n;
    int board[n];
    cout << rec(n, 0, 0, board) << endl;
    return 0;
}

// DONE
