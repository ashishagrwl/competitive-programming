#include <bits/stdc++.h>
using namespace std;

int main() {
    //ios::sync_with_stdio(false);
    priority_queue<int> max_pq;
    priority_queue<int, std::vector<int>, std::greater<int> > min_pq;
    unordered_multiset<int> htable;
    int t = 0;
    scanf("%d", &t);
    while (t--) {
        int q=0;
        scanf("%d", &q);
        switch (q) {
            case 1: {
                int n=0;
                scanf("%d", &n);
                max_pq.push(n);
                min_pq.push(n);
                htable.insert(n);
                break;
            }
            case 2: {
                int n=0;
                scanf("%d", &n);
                auto pit = htable.equal_range(n);
                if (pit.first == htable.end()) {
                    printf("-1\n");
                } else {
                    htable.erase(pit.first);
                }
                break;
            }
            case 3: {
                int out = -1;
                if (!htable.empty()) {
                    out = max_pq.top();
                    while (htable.find(out) == htable.end()) {
                        max_pq.pop();
                        out = max_pq.top();
                    }
                }
                printf("%d\n", out);
                break;
            }
            case 4: {
                int out = -1;
                if (!htable.empty()) {
                    out = min_pq.top();
                    while (htable.find(out) == htable.end()) {
                        min_pq.pop();
                        out = min_pq.top();
                    }
                }
                printf("%d\n", out);
                break;
            }
        }
    }
    //cout << flush;
    return 0;
}

// int main() {
//     multiset<int> mset;
//     int t = 0;
//     scanf("%d", &t);
//     while (t--) {
//         int q=0;
//         scanf("%d", &q);
//         switch (q) {
//             case 1: {
//                 int n=0;
//                 scanf("%d", &n);
//                 mset.insert(n);
//                 break;
//             }
//             case 2: {
//                 int n=0;
//                 scanf("%d", &n);
//                 auto pit = mset.equal_range(n);
//                 if (pit.first == pit.second) {
//                     printf("-1\n");
//                 } else {
//                     mset.erase(pit.first);
//                 }
//                 break;
//             }
//             case 3: {
//                 if (mset.empty()) {
//                     printf("-1\n");
//                     break;
//                 }
//                 int out = *(mset.rbegin());
//                 printf("%d\n", out);
//                 break;
//             }
//             case 4: {
//                 if (mset.empty()) {
//                     printf("-1\n");
//                     break;
//                 }
//                 int out = *(mset.begin());
//                 printf("%d\n", out);
//                 break;
//             }
//         }
//     }
//     //cout << flush;
//     return 0;
// }