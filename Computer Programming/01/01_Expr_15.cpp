#include<bits/stdc++.h>
using namespace std;

int main()
{
    double x;
    cin >> x;

    double y = pow(x, pow(2*log(x+1),0.5) ) / (10-x);

    

    cout << round(y*1e6)/1e6 ;

}