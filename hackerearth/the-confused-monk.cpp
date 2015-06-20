#include <bits/stdc++.h>
using namespace std;
const int monk = 1000000007;

long long int mypow(long long int base, long long int exp, const long long int modul) {
    auto result = 1LL;
    while (exp) {
        if (exp&1)
            result=(result*base)%modul;
        base=(base*base)%modul;
        exp >>= 1;
    }
    return result;
}

int gcd(int a,int b) {
    while(b^=a^=b^=a%=b);
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    auto t = 0;
    auto g=0LL;
    cin >> t;
    cin >> g;
    auto f=g;
    t--;
    while (t--) {
        auto x=0LL;
        cin >> x;
        g=gcd(g, x);
        f=f*(x%monk);
        f%=monk;
    }
    long long int result = mypow(f, g, monk);
    cout << result;
    cout << flush;
    return 0;
}