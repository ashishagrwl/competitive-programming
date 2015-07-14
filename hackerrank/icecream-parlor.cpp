#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t = 0;
    cin >> t;
    while (t--) {
        unordered_map<int, int> hashm;
        int m=0, n=0, c=0, i=1;
        bool found=false;
        cin >> m >> n >> c;
        hashm.insert(std::make_pair(c, 0));
        for (i = 1; i < n; ++i) {
            int c=0;
            cin >> c;
            if (!found) {
                unordered_map<int, int>::const_iterator findres = hashm.find(m-c);
                if (findres != hashm.end()) {
                    found = true;
                    cout << (findres->second)+1 << " " << i+1 << '\n';
                    continue;
                }
                hashm.insert(make_pair(c, i));
            }
        }
    }
    cout << flush;
    return 0;
}