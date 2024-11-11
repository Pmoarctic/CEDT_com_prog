#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define in(x) != x.end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef priority_queue<pii, vector<pii> , greater<pii> > gpiiq;

int main()
{
    int cnt[4]={};
    int n;
    cin >> n;
    vi v(n);
    for(auto &i:v)
    {
        cin >> i;
        cnt[i]++;
    }

    ///////////////
    vi s=v;
    sort(all(s));
    if(s==v)
    {
        cout << 0;
        return 0;
    }
    ///////////////

    int num1in2=0,num1in3=0,num2in3=0;
    int num2in1=0,num3in1=0,num3in2=0;

    for(int i=0;i<cnt[1];i++)
    {
        if(v[i]==2)
            num2in1++;
        if(v[i]==3)
            num3in1++;
    }
    for(int i=cnt[1];i<cnt[1]+cnt[2];i++)
    {
        if(v[i]==1)
            num1in2++;
        if(v[i]==3)
            num3in2++;
    }
    for(int i=cnt[1]+cnt[2];i<cnt[1]+cnt[2]+cnt[3];i++)
    {
        if(v[i]==1)
            num1in3++;
        if(v[i]==2)
            num2in3++;
    }

    int res1=0,res2=0;

    res1 += min(num1in2,num2in1);
    res1 += min(num1in3,num3in1);
    res1 += min(num2in3,num3in2);

    res2 += abs(num1in2-num2in1);
    res2 += abs(num1in3-num3in1);
    res2 += abs(num2in3-num3in2);


    cout << res1+(res2*2)/3;


    return 0;
}