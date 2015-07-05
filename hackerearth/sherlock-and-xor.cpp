//https://www.hackerearth.com/july-easy-challenge/algorithm/sherlock-and-xor/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t = 0;
    cin >> t;
    while (t--) {
        auto n=0;
        auto odd=0LL, even=0LL, total=0LL;
        cin >> n;
        while (n--) {
            int i=0;
            cin >> i;
            if (i&1) {
                total += even;
                odd++;
            } else {
                total += odd;
                even++;
            }
        }
        cout << total << '\n';
    }
    cout << flush;
    return 0;
}