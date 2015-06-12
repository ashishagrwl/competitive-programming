#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t = 0;
    cin >> t;
    while (t--) {
        int i = 0, size = 0, sum = 0;
        bool good = false;
        cin >> size;
        vector<int> numbers, left_sum;
        for (i = 0; i < size; ++i) {
            int temp = 0;
            cin >> temp;
            numbers.push_back(temp);
            left_sum.push_back(sum);
            sum += temp;
        }
        if (1 == size) {
            cout << "YES" << endl;
            continue;
        }
        for (i = 1; i < size; ++i) {
            if (left_sum.at(i) == (sum-numbers.at(i)-left_sum.at(i))) {
                good = true;
                break;
            }
        }
        cout << (good?"YES\n":"NO\n");
    }
    return 0;
}