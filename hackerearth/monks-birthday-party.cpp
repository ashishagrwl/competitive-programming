#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t = 0;
    cin >> t;
    while (t--) {
        int n=0;
        cin >> n;
        set<string> names;
        for (int i = 0; i < n; ++i) {
            string tmp;
            cin >> tmp;
            names.insert(tmp);
        }
        for (auto&& name: names)
            cout << name << '\n';
    }
    cout << flush;
    return 0;
}