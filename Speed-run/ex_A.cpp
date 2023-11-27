#include <iostream>

using namespace std;

int main() {
    int x;
    cin >> x;
    unsigned long long i_square = 1, i_cube = 1;
    unsigned long long temp_sq = 1, temp_cb = 1;
    // unsigned long long tmp_last=-1;
    for (int i = 1; i <= x; i++) { 
        
        if (temp_sq < temp_cb) {
            if (i == x)
                cout << temp_sq << endl;
            i_square++;
            temp_sq = i_square * i_square;
            // if (temp_sq == tmp_last) {
            //     i_square++;
            //     temp_sq = i_square * i_square;
            //     i--;
            //     continue;
            // }
            // tmp_last = temp_sq;
        }
        else if (temp_sq > temp_cb) {
            if (i == x)
                cout << temp_cb << endl;
            i_cube++;
            temp_cb = i_cube * i_cube * i_cube;
            // if (temp_sq == tmp_last) {
            //     i_cube++;
            //     temp_cb = i_cube * i_cube * i_cube;
            //     i--;
            //     continue;
            // }
            // tmp_last = temp_cb;
        }
        else {
            i_square++;
            temp_sq = i_square*i_square;
            i--;
        }
    }
    // if (temp_sq <= temp_cb)
    //     cout << temp_sq << endl;
    // else
    //     cout << temp_cb << endl;
    return 0;
}

// DONE
