#include<bits/stdc++.h>
using namespace std;

int main()
{
    int xe,ye,re,rp,xm,ym;
    cin >> xe >> ye >> re >> rp >> xm >> ym;
    
    double A = xm-xe;
    double B = ym-ye;
    double C = sqrt(A*A + B*B);
    double c = re-rp;

    double a = (c/C)*A;
    double b = (c/C)*B;

    //cout << A << " " << B << " " << C << " " << c << endl;
    //cout << a << " " << b ;
    cout << round(xe+a) << " " << round(ye+b);

}