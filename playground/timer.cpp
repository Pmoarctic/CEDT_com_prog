#include<bits/stdc++.h>
using namespace std;
int MOD = 1000000007;



int main()
{
    clock_t sssss,eeeee;
    sssss = clock();

    int n;
    cin >> n;
    unsigned long long sum =0;
    unsigned long long t;
    while(n--)
    {
        cin >> t;
        sum += t%MOD;
    }

    eeeee = clock();
    
    double time_taken = double(eeeee - sssss) / double(1000000);
    cout << time_taken << "\n";
    if(time_taken>1.0){cout << "time limit exceed\n";}
    else
    {
        cout << MOD-(sum%MOD);
    }
}