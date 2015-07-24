#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t = 0, i1=-1, i2=-1, i3=-1;
    cin >> t;
    while (t--) {
        int n=0;
        cin >> n;
        if (n > i3) {
            i3 = n;
            if (i3 > i2)
                i3 ^= i2 ^= i3 ^= i2;
            if (i2 > i1)
                i2 ^= i1 ^= i2 ^= i1;
        }
        if (-1 == i3)
            cout << i3 << '\n';
        else {
            cout << (i1 * 1LL * i2 * 1LL * i3) << '\n';
        }
    }
    cout << flush;
    return 0;
}