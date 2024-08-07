#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;

    string tmp = "";
    int sum=0;
    int id = 13;
    for(int i=0;i<str.size();i++)
    {
        if(i == 1 || i == 5 || i == 10)
        {
            tmp += "-";
        }
        sum += (str[i]-'0')*id;
        tmp += str[i];
        id--;
    }

    int n12 = (11 - (sum%11))%10;

    cout << tmp << "-" << n12;
}