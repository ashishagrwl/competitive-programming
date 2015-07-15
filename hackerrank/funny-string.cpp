#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t = 0;
    cin >> t;
    while (t--) {
        int i=1;
        string input;
        cin >> input;
        int mid_idx = (input.length()+1)/2-1;
        while (i<=mid_idx) {
            if (abs(input.at(i)-input.at(i-1)) != abs(input.at(input.length()-i-1)-input.at(input.length()-i)))
                break;
            ++i;
        }
        if (i > mid_idx)
            cout << "Funny\n";
        else
            cout << "Not Funny\n";
    }
    cout << flush;
    return 0;
}