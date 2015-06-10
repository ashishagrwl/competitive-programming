#include <bits/stdc++.h>
using namespace std;
int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        int size = 0;
        std::vector<int> numbers;
        cin >> size;
        while (size--) {
            int i = 0;
            cin >> i;
            numbers.push_back(i);
        }
        std::sort(numbers.begin(), numbers.end(), std::greater<int>());
        for (std::vector<int>::iterator ii = numbers.begin(); ii != numbers.end(); ++ii) {
            cout << *ii << " ";            
        }
        cout << endl;
    }
    return 0;
}