#include<bits/stdc++.h>
using namespace std;

int main()
{
    double Pi = M_PI;//
    double b = (3628800.0)/(16777216.0);//
    double c = log(9.7);
    double d = ((7.0)/(pow(71,0.5))) - sin(0.698132);//
    
    double e = pow(2.3,1.0/3.0);
    double e2 = pow(1.2,e);

    double res = (Pi-b+pow(c,d))/(e2);

    cout << setprecision(6) << res;
}