#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        string input;
        cin >> input;
        int sum = 0;
        for (int i = 0 ; i < input.length(); i++) { sum += (input.at(i)-'0'); }
        int  remain = sum%9;
        if (sum <= 9)
            cout << 9-sum << '\n';
        else {
            if (remain>4) { remain = 9-remain; }
            cout << remain << '\n';
        }
    }
    cout << flush;
    return 0;
}