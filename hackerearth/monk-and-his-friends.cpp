#include <bits/stdc++.h>
using namespace std;

int main() {
    //ios::sync_with_stdio(false);
    int t = 0;
    //cin >> t;
    scanf("%d", &t);
    while (t--) {
        int n=0, m=0;
        //cin >> n >> m;
        scanf("%d%d", &n, &m);
        set<unsigned long long int> candyset;
        vector<bool> result(m);
        for (int i = 0; i < n; ++i) {
            unsigned long long int tmp=0LL;
            scanf("%llu", &tmp);
            candyset.insert(tmp);
        }
        for (int i = 0; i < m; ++i) {
            unsigned long long int tmp=0LL;
            scanf("%llu", &tmp);
            if (!(result.at(i) = (candyset.find(tmp) != candyset.end())))
                candyset.insert(tmp);
        }
        for (std::vector<bool>::iterator b = result.begin(); b != result.end(); ++b) {
            printf("%s\n", (*b?"YES":"NO"));
        }
    }
    return 0;
}