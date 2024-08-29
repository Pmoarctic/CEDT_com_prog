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
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef priority_queue<pii, vector<pii> , greater<pii> > gpiiq;

map<int,map<int,map<int,map<int,vector<int> > > > > mp;

//   0 1    0 1
// 0      0
// 1      1
vector<vector<int> > multiplymat(vector<vector<int> > a,vector<vector<int> > b)
{
    vector<vector<int> > product = {{0,0},{0,0}};
    product[0][0] = a[0][0]*b[0][0] + a[0][1]*b[1][0];
    product[0][1] = a[0][0]*b[0][1] + a[0][1]*b[1][1];
    product[1][0] = a[1][0]*b[0][0] + a[1][1]*b[1][0];
    product[1][1] = a[1][0]*b[0][1] + a[1][1]*b[1][1];
    return product;
}

int n,k;
void printmat(vector<vector<int> > a)
{
    cout << a[0][0]%k << " " << a[0][1]%k << "\n";
    cout << a[1][0]%k << " " << a[1][1]%k << "\n\n";
    return;
}

int main()
{
    
    cin >> n >> k;

    vector<vector<int> > mat = {{0,0},{0,0}},og;
    cin >> mat[0][0] >> mat[0][1] >> mat[1][0] >> mat[1][1];
    og = mat;

    for(int i=1;i<n;i++)
    {
        mat = multiplymat(mat,og);
    }

    printmat(mat);

    return 0;
}