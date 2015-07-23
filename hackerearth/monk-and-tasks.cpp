#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t = 0;
    cin >> t;
    while (t--) {
        vector< vector<unsigned long long int> > buckets(64);
        int n=0;
        cin >> n;
        while (n--) {
            unsigned long long int input=0, copy=0;
            int bit_count=0;
            cin >> input;
            copy = input;
            while (copy) {
                copy &= (copy-1);
                bit_count++;
            }
            buckets[bit_count].push_back(input);
        }
        for (auto&& v: buckets) {
            for (auto&& l: v) {
                cout << l << " ";
            }
        }
        cout << '\n';
    }
    cout << flush;
    return 0;
}