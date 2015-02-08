#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N=0, K=0, candies=0, unfairness=0;
    vector<int> packet;
    vector<int>::iterator it1, it2;
    cin >> N >> K;
    for (int i=0; i<N; i++)
    {
        cin >> candies;
        packet.push_back(candies);
    }
//    for (it1=packet.begin(); it1!=packet.end(); it1++)
//    {
//        cout << *it1 << " ";
//    }
//    cout << endl;
    sort(packet.begin(), packet.end());
//    for (it1=packet.begin(); it1!=packet.end(); it1++)
//    {
//        cout << *it1 << " ";
//    }
//    cout << endl;
    for (it1 = packet.begin(), it2=it1+K-1, unfairness=*it2-*it1; it2<packet.end(); it1++, it2++)
    {
        unfairness=min(unfairness, (*it2-*it1));
    }
    cout << unfairness;
    return 0;
}
