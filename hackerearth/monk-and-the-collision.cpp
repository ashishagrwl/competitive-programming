#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t = 0;
    cin >> t;
    while (t--) {
        bool buckets[10] = {false};
        int n=0, collisions=0;
        cin >> n;
        while (n--) {
            int num = 0;
            cin >> num;
            if (buckets[(num%10)])
                collisions++;
            else
                buckets[(num%10)] = true;
        }
        cout << collisions << '\n';
    }
    cout << flush;
    return 0;
}