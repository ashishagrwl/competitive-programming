#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t = 0;
    cin >> t;
    while (t--) {
        auto n=0, m=0;
        auto max_coins=0LL, curr_coins=0LL;
        cin >> n >> m;
        vector< vector<int> > graph(n+1);
        vector<bool> visited(n+1);
        vector<long long> bananas(n+1);
        for (int i = 0; i < m; ++i) {
            int p=0, q=0;
            cin >> p >> q;
            graph[p].push_back(q);
            graph[q].push_back(p);
        }
        for (int i = 1; i <= n; ++i) {
            cin >> bananas[i];
        }
        for (int i = 1; i <= n; ++i) {
            stack<int> st;
            if (visited[i])
                continue;
            visited[i] = true;
            st.push(i);
            for (auto&& ii: graph[1]) {
                if (!visited[ii]) {
                    visited[ii] = true;
                    st.push(ii);
                }
            }
            while (!st.empty()) {
                int p = st.top();
                st.pop();
                curr_coins += bananas[p];
                for (auto&& i: graph[p]) {
                    if (!visited[i]) {
                        visited[i] = true;
                        st.push(i);
                    }
                }
            }
            if (curr_coins > max_coins)
                max_coins = curr_coins;
            curr_coins = 0;
        }
        cout << max_coins << '\n';
    }
    cout << flush;
    return 0;
}