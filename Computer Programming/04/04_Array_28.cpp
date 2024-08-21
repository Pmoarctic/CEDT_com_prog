#include<bits/stdc++.h>
using namespace std;

int arr[200]={};

int main()
{
    string s;
    getline(cin,s);

    for(int i=0;i<s.size();i++)
    {
        char c = tolower(s[i]);
        arr[c]++;
    }

    for(int i='a';i<='z';i++)
    {
        if(arr[i]!=0)
        {
            cout << (char)i << " -> " << arr[i] << '\n';
        }
    }

}
