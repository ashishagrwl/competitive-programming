#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int m=0, n=0;
    auto total=0LL;
    cin >> m >> n;
    priority_queue<int> price;
    while (m--) {
        int p=0;
        cin >> p;
        price.push(p);
    }
    while (n-- && !price.empty()) {
        int x = price.top();
        total += x;
        x--;
        price.pop();
        if (x) {
            price.push(x);
        }
    }
    cout << total;
    cout << flush;
    return 0;
}