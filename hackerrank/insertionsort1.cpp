#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

void insertionSort(vector <int>  ar) {
    int item = ar.back();
    for (int i = ar.size() - 2; i >= 0; i--) {
        if (item < ar.at(i))
            ar.at(i + 1) = ar.at(i);
        else {
            ar.at(i + 1) = item;
            i = -1;
        }
        for (vector<int>::iterator ii = ar.begin(); ii != ar.end(); ii++) {
            cout << *ii << " ";
        }
        cout << endl;
        if (i == 0) {
            ar.front() = item;
            for (vector<int>::iterator ii = ar.begin(); ii != ar.end(); ii++) {
                cout << *ii << " ";
            }
            cout << endl;
        }
    }
}

int main(void) {
    vector <int>  _ar;
    int _ar_size;
    cin >> _ar_size;
    for (int _ar_i = 0; _ar_i<_ar_size; _ar_i++) {
        int _ar_tmp;
        cin >> _ar_tmp;
        _ar.push_back(_ar_tmp);
    }
    insertionSort(_ar);
    return 0;
}