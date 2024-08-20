#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin,s);

    int arr[200] = {};

    for(int i=0;i<s.size();i++)
    {
        if('A'<=s[i] && s[i]<='Z')
        {
            s[i] += 32;
        }
        arr[s[i]]++;
    }

    for(char i='a';i<='z';i++)
    {
        if(arr[i]!=0)
        {
            cout << i << " -> " << arr[i] << "\n";
        }
    }

}
/* line=2
4 1 5 2 7 3 6 8
cnt=7
*/

/*
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
*/
