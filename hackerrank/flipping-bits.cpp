#include <bits/stdc++.h>

using namespace std;

int main() {
    int t=0;
    scanf("%d", &t);
    while (t--) {
        unsigned int n=0;
        if (scanf("%d", &n))
            printf("%u\n", ~n);
    }
    return 0;
}