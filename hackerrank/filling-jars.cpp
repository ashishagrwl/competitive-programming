#include <iostream>
using namespace std;
long long int N, M;
long long int total;
long long int average;
int main()
{
    cin >> N >> M;
    while (M--)
    {
        long long int a=0, b=0, k=0;
        cin >> a >> b >> k;
        total=total+(k*(b-a+1));
    }
    average = total/N;
    cout << average;
    return 0;
}