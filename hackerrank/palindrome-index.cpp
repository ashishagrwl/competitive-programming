#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int half_index = 0, far_index = 0, t = 0;
    cin >> t;
    cin.ignore(2, '\n');
    while (t--) {
        int i = 0;
        char input[100006];
        getline(cin, input);
        int far_index = strlen(input) - 1;
        half_index = (far_index - 1) / 2;
        for (; i <= half_index; i++) {
            if (input[i] == input[far_index - i])
                continue;
            if (input[i] == input[far_index - i - 1]) {
                cout << far_index - i << endl;
                break;
            }
            else {
                cout << i << endl;
                break;
            }
        }
        if (i > half_index) {
            cout << "-1" << endl;
        }
    }
    return 0;
}