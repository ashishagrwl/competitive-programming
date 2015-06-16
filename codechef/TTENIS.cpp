#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t = 0;
    cin >> t;
    while (t--) {
        string input;
        cin >> input;
        int i=0, wins=0, losses=0;
        if (input.length() >= 22) {
            i = 20;
            while (i < input.length()) {
                if ('0' == input.at(i)) losses++;
                else wins++;
                if (wins > (losses+1)) {
                    cout << "WIN\n";
                    break;
                } else if (losses > (wins+1)) {
                    cout << "LOSE\n";
                    break;
                }
                i++;
            }
        } else {
            while (i < input.length()) {
                if ('0' == input.at(i)) losses++;
                else wins++;
                if (11==wins) {
                    cout << "WIN\n";
                    break;
                } else if (11==losses) {
                    cout << "LOSE\n";
                    break;
                }
                i++;
            }
        }
    }
    cout << flush;
    return 0;
}