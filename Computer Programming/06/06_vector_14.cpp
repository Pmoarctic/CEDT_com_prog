#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define st first
#define nd second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<ll> vll;
typedef vector<ull> vull;


int main()
{
    vector<int> k;
    int arr[50000]={};

    int n;
    while(cin >> n)
    {
        arr[n]++;
        if(arr[n]==1)
        {
            k.pb(n);
        }
    }

    cout << k.size() <<'\n';
    sort(all(k));
    for(int i=0;i<k.size();i++)
    {
        if(i>=10)
        {
            break;
        }
        cout << k[i] << " ";
    }



}