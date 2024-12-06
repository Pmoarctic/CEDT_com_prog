#include<bits/stdc++.h>
using namespace std;

int main()
{
    list<int> lis;
    lis.push_back(1);
    lis.push_back(2);
    lis.push_back(3);
    lis.push_back(4);
    lis.push_back(5);
    for(auto &i:lis)
    {
        i = 5;
    }

    for(auto i:lis)
    {
        cout << i << " ";
    }
}