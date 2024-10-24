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

    vector<int> arr = {1,1,1,2,2,2,3,4,5,6,6,6,6,6,7,7,7,7,7,7,8,8,8,8,8,9,9,9,9,9};
    int target = 7;

    int l = 0;
    int r = arr.size()-1;
    int mid,ans=arr.size();

    while(l<=r)
    {
        mid = (l+r)/2;
        if(arr[mid]>=target)
        {
            ans = mid;
            r = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }

    cout << "lower_bound : " << ans << "\n";

    l = 0;
    r = arr.size()-1;
    ans = arr.size();

    while(l<=r)
    {
        mid = (l+r)/2;
        if(arr[mid]>target)
        {
            ans = mid;
            r = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }

    cout << "upper_bound : " << ans;

    return 0;
}