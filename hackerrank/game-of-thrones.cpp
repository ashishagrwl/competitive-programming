#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    string s;
    int count=0;
    cin>>s;
    int sum=0;
    int alpha[26] = {0};
    int flag = 0;
    
    for (int i=0; i<s.length(); i++)
    {
	int index = s[i]-'a';
	//cout << index << endl;
	alpha[index]^=1;
    }

    for (int i=0; i<26; i++)
    {
	sum+=alpha[i];
    }
    if ((s.length())%2 == sum)
	    flag=1;

    // Assign Flag a value of 0 or 1 depending on whether or not you find what you are looking for, in the given string 
    if(flag==0)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}
