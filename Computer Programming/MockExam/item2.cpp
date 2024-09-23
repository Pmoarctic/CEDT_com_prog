#include<bits/stdc++.h>
using namespace std;

int main()
{
    double x;
    cin >> x;

    double up = sqrt(x*x + pow(cos(x*M_PI/180.0),2));
    double down = sin(x*M_PI/180.0) + (pow(cos(x*M_PI/180.0),3)/(x*x+1));

    cout << fixed << setprecision(1) << up/down;
}