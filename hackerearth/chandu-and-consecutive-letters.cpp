#include <bits/stdc++.h>

using namespace std;

int main() {
    int t = 0;
    scanf("%d", &t);
    while (t--) {
        string str;
        cin >> str;
        printf("%c", str.at(0));
        for (int i = 1; i < str.size(); ++i) {
            if (str.at(i) == str.at(i-1))
                continue;
            printf("%c", str.at(i));
        }
        cout << endl;
    }
    return 0;
}