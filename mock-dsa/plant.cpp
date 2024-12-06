#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define MOD 1000000007

ull n;
ull n_2=0;
ull n_1=1;
ull cur_n;

int main()
{
    
    cin >> n;

    if(n==1)
    {
        cout << 1;
    }

    for(ull i=2;i<=n+1;i++)
    {
        cur_n = n_1;
        cur_n += 2*n_2;


        cur_n %= MOD;
        n_2 = n_1;
        n_1 = cur_n;
        
    }
    cout << cur_n << "\n";
}