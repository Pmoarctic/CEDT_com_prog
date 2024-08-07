#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a;
    cin >> a;
    a -= 543;
    int y = a%100;

    //double k = y/4.0;
    int tmp = y + 11 + floor(y/4.0);

    int r = tmp%7;

    cout << r;

}