#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n = 0, min_diff = 0x7fffffff;
    cin >> n;
    vector<int> items;
    vector<int> pairs;
    for (int i = 0; i < n; ++i) {
        int tmp = 0;
        cin >> tmp;
        items.push_back(tmp);
    }
    sort(items.begin(), items.end());
    for (std::vector<int>::iterator ii = items.begin()+1; ii != items.end(); ++ii) {
        if ((*ii - *(ii-1)) < min_diff) {
            min_diff = (*ii - *(ii-1));
            pairs.clear();
        }
        if ((*ii - *(ii-1)) <= min_diff) {
            pairs.push_back(*(ii-1));
            pairs.push_back(*ii);
        }
    }
    for (std::vector<int>::iterator ii = pairs.begin(); ii != pairs.end(); ++ii) {
        cout << *ii << " ";
    }
    return 0;
}