#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define in(x) != x.end()
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef priority_queue<pii, vector<pii> , greater<pii> > gpiiq;

struct OBJ
{
    int a,b,c;

    bool operator <(const OBJ &x) const{
        return x.a<a;
    };
};


int r,c;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> c;
    int wei[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin >> wei[i][j];
        }
    }
    vector<vi> dis(r,vi(c,INT_MAX));
    dis[0][0] = 0;
    queue<tiii> q;
    q.push({0,0,0});
    
    int dr[4] = {0,1,0,-1};
    int dc[4] = {1,0,-1,0};
    while(!q.empty())
    {
        auto [cur_dis,cur_r,cur_c] = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int next_r = cur_r+dr[i];
            int next_c = cur_c+dc[i];
            if(next_r<0 || next_c<0 || next_r>=r || next_c>=c)continue;

            if(cur_dis + wei[next_r][next_c] < dis[next_r][next_c])
            {
                dis[next_r][next_c] = cur_dis + wei[next_r][next_c];
                q.push({dis[next_r][next_c],next_r,next_c});
            }
        }
    }

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout << dis[i][j] << " ";
        }
        cout << "\n";
    }



    return 0;
}