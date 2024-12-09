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

int r,c;
vector<vi> road(1010,vi(1010,0));

pair<int,int> dfs(int ii,int jj)
{
   int cnt=0;
   int cycle=0;
   int start_i=ii,start_j=jj;

   stack<tuple<int,int,char> > st;
   st.push({ii,jj,'-'});

   while(!st.empty())
   {
      auto [i,j,prev] = st.top();
      st.pop();
      if(i==start_i && j==start_j && cnt!=0)
      {
         cycle=1;
         return {1,cnt};
         break;
      }
      if(i<0||j<0||i>=r||j>=c || road[i][j]==0)
      {
         continue;
      }

      cnt++;

      int type = road[i][j];
      road[i][j] = 0;
      if(type==1){
         if(prev=='l')
         {
            st.push({i,j+1,'l'});
         }
         else
         {
            st.push({i,j-1,'r'});
         }
      }
      else if(type==2){
         if(prev=='d')
         {
            st.push({i-1,j,'d'});
         }
         else
         {
            st.push({i+1,j,'u'});
         }
      }
      else if(type==3){
         if(prev=='r')
         {
            st.push({i-1,j,'d'});
         }
         else
         {
            st.push({i,j+1,'l'});
         }
      }
      else if(type==4){
         if(prev=='d')
         {
            st.push({i,j+1,'l'});
         }
         else
         {
            st.push({i+1,j,'u'});
         }
      }
      else if(type==5){
         if(prev=='l')
         {
            st.push({i+1,j,'u'});
         }
         else
         {
            st.push({i,j-1,'r'});
         }
      }
      else if(type==6){
         if(prev=='u')
         {
            st.push({i,j-1,'r'});
         }
         else
         {
            st.push({i-1,j,'d'});
         }
      }
   }

   //cout << cycle << " " << cnt << " <<\n";
   return {0,0};
}

int main()
{
   cin >> r >> c;
   for(int i=0;i<r;i++)
   {
      for(int j=0;j<c;j++)
      {
         cin >> road[i][j];
         
      }
   }

   int mx=0;
   int lo=0;
   for(int i=0;i<r;i++)
   {
      for(int j=0;j<c;j++)
      {
         if(road[i][j]==0)continue;
         auto [res1,res2] = dfs(i,j);
         if(res1==0)continue;
         lo += res1;
         mx = max(mx,res2);
      }
   }

   

   cout << lo << " " << mx;

   return 0;
}
/*
4 5
4 1 5 1 2
2 1 3 5 3
3 1 1 6 4
1 2 4 1 6

4 4
4 5 4 5
2 2 3 6
2 3 1 5
3 1 1 6
*/