#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;

struct PARTY
{
    string name;
    ll member=0;
    double score=0;
    ll keep=0;
};

unordered_map<string,ll> mp;
vector<PARTY> lis;

bool sortScore(PARTY a,PARTY b)
{
    return a.score>b.score;
}
bool sortMember(PARTY a,PARTY b)
{
    if(a.member!=b.member)
    {
        return a.member>b.member;
    }
    else
    {
        return a.keep>b.keep;
    }
    
}

int main()
{
    double alltotal=0;
    ll n=0;
    string str;
    double tmp;
    while(cin >> str && str!="END")
    {
        cin >> tmp;
        mp[str] = n;
        lis.pb({str,0,tmp,(ll)tmp});

        n++;
        alltotal += tmp;
    }
    double avg = alltotal/100.0;

    ll totalmember=0;
    for(int i=0;i<n;i++)
    {
        lis[i].member = (ll)floor(lis[i].score/avg);
        lis[i].score = lis[i].score/avg - (double)lis[i].member;
        totalmember += lis[i].member;
    }

    sort(all(lis),sortScore);
    int i=0;
    while(totalmember != 100)
    {
        lis[i].member++;
        totalmember++;
        i++;
    }
    //cout << totalmember << "\n";

    sort(all(lis),sortMember);
    for(int i=0;i<n;i++)
    {
        if(lis[i].member)
        cout << lis[i].name << " " << lis[i].member << " " << lis[i].keep << '\n';
    }

    

}
/*
AA 100000
BB 120000
CC 170000
DD 550
EE 250000
FF 7000
GG 6300
END

ANT 81718
CC 7759
CPK 212676
CRR 4433
CTP 192497
GRE 22047
KK 14438851
KLT 7959
KTP 175182
KVM 10891
MAI 249731
MTM 33558
NTM 10875
PAK 23381
PCC 602645
PCH 59571
PCM 273428
PCP 925349
PCT 134833
PCW 17686
PDT 10690
PJT 1138202
PKK 58010
PKT 57098
PLE 53706
PLG 156493
PLK 10158
PLS 17076
PPC 5022
PPC 8818
PPR 537625
PPT 44131
PRP 3455
PRT 32428
PSK 5534
PSM 177379
PSN 10001
PT 10962522
PTC 9174
PTH 184817
PTM 33770
PTR 67692
RJT 72719
RPD 11010
RPL 33844
RPT 12601
RSC 130147
RTS 4766408
RVT 6172
SD 10410
SKP 5860
SMC 6509
SMP 11816
SRT 351376
TCN 45321
TGK 5561
TKN 35094
TLM 79190
TPD 103472
TPN 13605
TPR 82965
TRT 72988
TSL 23721
TSM 10463
TST 340178
TTM 21022
TTT 201411
END
*/
