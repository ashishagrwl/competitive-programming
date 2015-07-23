#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t = 0;
    cin >> t;
    while (t--) {
        int n=0, count=0;
        cin >> n;
        unordered_multiset<int> food;
        while (n--) {
            int a=0, b=0;
            cin >> a >> b;
            if (b == a)
                continue;
            pair<unordered_multiset<int>::iterator, unordered_multiset<int>::iterator> pit = food.equal_range(b);
            if (pit.first == food.end()) {
                count++;
            }
            else
                food.erase(pit.first);
            food.insert(a);
        }
        cout << count << '\n';
    }
    cout << flush;
    return 0;
}