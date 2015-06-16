#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t = 0;
    char input[100001];//, mirror[100001];
    memset(input, 0, 100001*sizeof(char));
    //map<int,int> idx_map;
    //memset(mirror, 0, 100001*sizeof(char));
    cin >> input;
    cin >> t;
    while (t--) {
        int i=0, j=0, k=0, l=0;//, begin_idx=0, end_idx=0;
        bool palindrome = true;
        cin >>i>>j>>k>>l;
        // begin_idx = min(i,k);
        // end_idx = max(j,l);
        // i -= begin_idx;
        // j -= begin_idx;
        // k -= begin_idx;
        // l -= begin_idx;
        // string temp(input+begin_idx-1, end_idx-begin_idx);
        i--;
        j--;
        k--;
        l--;
        // if ((i<k && j>k) || i<l) {
        //     int _i=i, _j=j;
        //     while (_i<_j) {
        //         idx_map[_j] = _i;
        //         idx_map[_i] = _j;
        //         _i++;
        //         _j--;
        //     }
        // }
        int p=k, q=l;
        while (k<l) {
            p=k;
            q=l;
            if (i <= p && p <= j) { p = i+(j-p); }
            if (i <= q && q <= j) { q = i+(j-q); }
            if (input[p]!=input[q]) {
                palindrome = false;
                break;
            }
            k++;
            l--;
        }
        cout << (palindrome?"Yes\n":"No\n");
        //idx_map.clear();
    }
    cout << flush;
    return 0;
}