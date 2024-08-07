#include<bits/stdc++.h>
using namespace std;

int main()
{
    double Pi = M_PI;//
    double b = 1.25 * 1.125 * 0.875 * 0.75 * 0.625 * 0.375;//
    double c = log(9.7);//2/9*Pi
    double d = ((7)/(pow(71,0.5))) - sin(0.698132);//
    
    double e = pow(2.3,0.3333);
    double e2 = pow(1.2,e);

    double res = (Pi-b+pow(c,d))/(e2);

    cout << setprecision(6) << fixed << res;
}