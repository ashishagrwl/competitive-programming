#include <bits/stdc++.h>

using namespace std;

int main() {
    int t=0;
    scanf("%d", &t);
    while (t--) {
        char input[100001];
        int output=0;
        scanf("%s", &input);
        for (int i = 1; input[i]!='\0'; ++i) {
            if (input[i] == input[i-1]) {
                output++;
            }
        }
        printf("%d\n", output);
    }
    return 0;
}