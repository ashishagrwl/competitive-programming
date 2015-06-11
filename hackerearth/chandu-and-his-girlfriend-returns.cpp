#include <bits/stdc++.h>
using namespace std;
int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        int size1 = 0, size2 = 0;
        std::vector<int> array1;
        std::vector<int> array2;
        cin >> size1 >> size2;
        array1.reserve(size1);
        array2.reserve(size2);
        while (size1--) {
            int tmp = 0;
            cin >> tmp;
            array1.push_back(tmp);
        }
        while (size2--) {
            int tmp = 0;
            cin >> tmp;
            array2.push_back(tmp);
        }
        vector<int>::iterator i1 = array1.begin();
        vector<int>::iterator i2 = array2.begin();
        while (i1 != array1.end() && i2 != array2.end()) {
            if (*i1 > *i2) {
                cout << *i1 << " ";
                ++i1;
            } else {
                cout << *i2 << " ";
                ++i2;
            }
        }
        while (i1 != array1.end()) {
            cout << *i1 << " ";
            ++i1;
        }
        while (i2 != array2.end()) {
            cout << *i2 << " ";
            ++i2;
        }
        cout << endl;
    }
    return 0;
}