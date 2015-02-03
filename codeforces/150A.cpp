#include <bits/stdc++.h>
using namespace std;

int main() {
    int n=0, m=0;
    string* output;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        if (i%2) {
            int j=m;
            while (j--)
                putchar('#');
            putchar('\n');
        }
        else {
            int j=m-1;
            if (!(i%4)) {
                putchar('#');
                while (j--)
                    putchar('.');
                putchar('\n');
            }
            else {
                while (j--)
                    putchar('.');
                putchar('#');
                putchar('\n');
            }
        }
    }
    return 0;
}