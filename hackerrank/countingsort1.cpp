#include <bits/stdc++.h>
using namespace std;
int main() {
    int t=0;
    int arr[100] = {0};
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        arr[n]++;
    }
    for (int i = 0; i < 100; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}