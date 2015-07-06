#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t = 0;
    cin >> t;
    while (t--) {
        auto n=0, k=0;
        auto sum=0LL;
        cin >> n >> k;
        priority_queue<long long int> pqueue;
        for (int i = 0; i < n; ++i) {
            auto tmp = 0LL;
            cin >> tmp;
            pqueue.push(tmp);
        }
        for (int i = 0; i < k; ++i) {
            auto tmp = pqueue.top();
            pqueue.pop();
            pqueue.push(tmp >> 1);
            sum += tmp;
        }
        cout << sum << '\n';
    }
    cout << flush;
    return 0;
}