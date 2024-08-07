#include<bits/stdc++.h>
using namespace std;

int main()
{
    double W,H;
    cin >> W >> H;

    double Mos = pow(W*H,0.5);
    Mos/=60.00;

    double Hay = 0.024265 * pow(W,0.5378) * pow(H,0.3964);

    double Boy = 0.0333 * pow(H,0.3) ;
    double tmp = 0.6157 - 0.0188*log10(W);
    Boy = Boy * pow(W,tmp);

    cout << setprecision(15) << Mos << "\n";
    cout << setprecision(15) << Hay << "\n";
    cout << setprecision(15) << Boy << "\n";
}