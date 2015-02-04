#include <iostream>
using namespace std;

int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        int n = 0, great_mult3 = 0, great_mult5 = 0, great_mult15 = 0;
        long long sum = 0;
        cin >> n;
        int i = n;
        while (i--) {
            if ((i % 3) == 0) {
                great_mult3 = i / 3;
                break;
            }
            if (i<3) {
                break;
            }
        }
        i = n;
        while (i--) {
            if ((i % 5) == 0) {
                great_mult5 = i / 5;
                break;
            }
            if (i<5) {
                break;
            }
        }
        i = n;
        while (i--) {
            if ((i % 15) == 0) {
                great_mult15 = i / 15;
                break;
            }
            if (i<15) {
                break;
            }
        }
        sum += 3 * great_mult3*(great_mult3 + 1);
        sum += 5 * great_mult5*(great_mult5 + 1);
        sum -= (15 * great_mult15*(great_mult15 + 1));
        sum /= 2;
        cout << sum << endl;
    }
    return 0;
}