#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string time12;
    cin >> time12;
    if ('1' == time12.at(0) && '2' == time12.at(1)) {
        if ('A' == time12.at(time12.length()-2))
            time12.at(0) = time12.at(1) = '0';
    }
    else if ('P' == time12.at(time12.length()-2)) {
        int carry = 1;
        int units = time12.at(1)-'0';
        units += 2;
        if (units>=10) {
            units %= 10;
            carry++;
        }
        time12.at(1) = '0'+units;
        time12.at(0) += carry;
    }
    time12.resize(time12.length()-2);
    cout << time12;
    cout << flush;
    return 0;
}