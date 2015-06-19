#include <bits/stdc++.h>
using namespace std;

bool isprime(int x) {
    for (int i = 3; (i*i) <= x; i+=2) {
        if (!(x%i))
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    auto t=0;
    cin >> t;
    while (t--) {
        auto x=0;
        cin >> x;
        if (x<6) {
            cout << "NO\n";
            continue;
        }
        if (!(x&1)) {
            cout << "YES\n";
            continue;
        }
        if ((sqrt(x) == floor(sqrt(x))) &&
            (isprime(sqrt(x)))) {
            cout << "NO\n";
            continue;
        }
        if (isprime(x)) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
    cout << flush;
    return 0;
}