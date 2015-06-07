#include <bits/stdc++.h>

using namespace std;

int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        int n = 0, lo = 0;
        long long int x = 0, sum = 0;
        cin >> n >> x;
        int* c = new int[n];
        for (int i = 0; i < n; ++i)
            cin >> c[i];
        for (int i = 0; i < n; ++i) {
            sum += c[i];
            while (sum > x)
                sum -= c[lo++];
            if (sum == x) {
                delete[] c;
                break;
            }
        }
        if (sum == x)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        delete[] c;
    }
    return 0;
}