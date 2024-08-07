#include<bits/stdc++.h>
using namespace std;

int main()
{
    double a,b,c;
    cin >> a >> b >> c;

    double dc = b*b - 4 * a * c;
    dc = pow(dc,0.5);

    double x1 = 0-b-dc, x2 = 0-b+dc;

    x1 /= 2*a;
    x2 /= 2*a;

    cout << round(x1*1e3)/1e3 << " " << round(x2*1e3)/1e3;

}