#include <bits/stdc++.h>
using namespace std;

long long int mypow(long long int base, int exp, const long long int modul) {
    auto result = 1LL;
    while (exp) {
        if (exp&1)
            result=(result*base)%modul;
        base=(base*base)%modul;
        exp >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    auto sum=0LL, A=0LL, B=0LL;
    string days;
    cin >> A >> B;
    cin >> days;
    for (unsigned int i = 0; i < days.size(); ++i) {
        if ('1' == days.at(i)) {
            sum+=A;
            sum %= B;
        }
        A*=A;
        A%=B;
    }
    cout << sum;
    cout << flush;
    return 0;
}