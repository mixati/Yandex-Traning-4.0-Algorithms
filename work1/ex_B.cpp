#include <iostream>
#include <vector>

using namespace std;

int ft_partition(vector<int> &a, int l, int r) {
    int tmp;
    int pivot = a[l + rand() % (r-l)];
    while (l <= r) {
        int y;
        while ((a[l]) < pivot)
            ++l;
        while (a[r] > pivot)
        	--r;
        if (l >= r)
        	break;
        tmp = a[l];
    	a[l++] = a[r];
    	a[r--] = tmp;
    }
    return r;
}


void ft_quicksort(vector<int> &a, int l, int r) {
    if (r > l) {
        int p = ft_partition(a, l, r);
        ft_quicksort(a, l, p);
        ft_quicksort(a, p+1, r);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int r = n-1, l = 0;
    ft_quicksort(a, l, r);
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
}
// DONE
