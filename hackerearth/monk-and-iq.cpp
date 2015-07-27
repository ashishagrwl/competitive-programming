#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int c=0, p=0, n=0;
    cin >> c >> p >> n;
    vector<int> count(c);
    vector< pair<int, int> > lastiq(c);
    priority_queue< pair<int,int>, vector < pair<int,int> >, std::greater< pair<int,int> > > pqueue;
    int temp = n;
    for (int i = 0; (i < c) && (i < (n+p)); ++i) {
        int iq=0;
        cin >> iq;
        count.at(i)++;
        lastiq.at(i).second = iq;
        lastiq.at(i).first ^= lastiq.at(i).second ^= lastiq.at(i).first ^= lastiq.at(i).second;
        int val = count.at(i)*(lastiq.at(i).first+lastiq.at(i).second);
        pqueue.push(make_pair(val, i));
        if (!temp)
            cout << (i+1) << " ";
        else
            temp--;
    }
    if ((p+n) <= c)
        return 0;
    for (int i = 0; i < (p-c+n); ++i) {
        int iq=0;
        cin >> iq;
        pair<int, int> pit = pqueue.top();
        pqueue.pop();
        count.at(pit.second)++;
        lastiq.at(pit.second).second = iq;
        lastiq.at(pit.second).first ^= lastiq.at(pit.second).second ^= lastiq.at(pit.second).first ^= lastiq.at(pit.second).second;
        int val = count.at(pit.second)*(lastiq.at(pit.second).first+lastiq.at(pit.second).second);
        pqueue.push(make_pair(val, pit.second));
        cout << pit.second+1 << " ";
    }
    cout << flush;
    return 0;
}