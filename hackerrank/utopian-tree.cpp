#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t = 0;
    cin >> t;
    while (t--) {
        int n=0;
        cin >> n;
        cout << ((1<<((n>>1)+1))-1)*1LL*(1<<(n&1)) << '\n';
    }
    cout << flush;
    return 0;
}