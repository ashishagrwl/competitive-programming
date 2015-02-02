#include <bits/stdc++.h>
using namespace std;

int main() {
    int t=0;
    cin >> t;
    while (t--) {
        int arr[26] = {0};
        int output = 0;
        string input;
        cin >> input;
        if (input.length()%2) {
            cout << "-1" << endl;
            continue;
        }
        int half = input.length()/2;
        for (int i = 0; i < half; ++i) {
            arr[input.at(i)-'a']+=1;
            arr[input.at(i)-'a']-=1;
        }
        for (int i = 0; i < 26; ++i)
            output+=abs(arr[i]);
        cout << output << endl;
    }
    return 0;
}