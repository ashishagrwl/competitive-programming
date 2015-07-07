// contest template
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t = 0;
    cin >> t;
    //set < pair<int, pair<string, int> > > results;
    multiset < pair<int, string> > results;
    while (t--) {
        string name;
        int marks;
        cin >> name >> marks;
        results.insert(make_pair(100-marks, name));
    }
    // for (std::set < pair<int, string> >::reverse_iterator i = results.rbegin(); i != results.rend(); ++i) {
    //     cout << i->second << " " << i->first << '\n';
    // }
    for (auto&& p: results) {
        cout << p.second << " " << (100 - p.first) << '\n';
    }
    cout << flush;
    return 0;
}