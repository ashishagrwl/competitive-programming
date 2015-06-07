#include <bits/stdc++.h>

using namespace std;

int main() {
    int t = 0;
    scanf("%d", &t);
    while (t--) {
        string str;
        cin >> str;
        int last_index = str.size() - 1;
        for (int i = 0; i < str.size()/2; ++i) {
            str.at(i) ^= str.at(last_index-i);
            str.at(last_index-i) ^= str.at(i);
            str.at(i) ^= str.at(last_index-i);
        }
        cout << str << endl;
    }
    return 0;
}