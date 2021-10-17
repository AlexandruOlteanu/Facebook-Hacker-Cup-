/*
    Programmer : Alexandru_Olteanu
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll const mod=1000000007LL;
ll const mod2=998244353LL;
ll mypowr(ll a,ll b) {ll res=1;if(b<0)b=0;a%=mod; assert(b>=0);
for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll mypow(ll a,ll b) {ll res=1;if(b<0)b=0;assert(b>=0);
for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}
ifstream in("input.txt");
ofstream out("output.txt");
#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()


//#define cin in
//#define cout out

const ll infll = 9e18;
const int inf = 2e9;
const ll maxn = 2e3 + 2;

bool c1[maxn], r1[maxn];
int c[maxn], r[maxn];
char c2[maxn][maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(15);

    
    int test = 1;
    cin>>test;
    int i = 1;
    while(test--){
        int n;
        cin>>n;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                cin>>c2[i][j];
                if(c2[i][j] == 'O'){
                    r1[i] = 1;
                    c1[j] = 1;
                }
                else{
                    if(c2[i][j] == 'X'){
                        ++r[i], ++c[j];
                    }
                }
            }
        }
        int cnt = inf, s = 0;
        for(int i = 1; i <= n; ++i){
            if(!r1[i]){
                if(n - r[i] == cnt){
                    ++s;
                }
                if(n - r[i] < cnt){
                    cnt = n - r[i];
                    s = 1;
                }
            }
            if(!c1[i]){
                if(n - c[i] == cnt){
                    ++s;
                }
                if(n - c[i] < cnt){
                    cnt = n - c[i];
                    s = 1;
                }
            }
        }
        if(cnt == 1){
            for(int i = 1; i <= n; ++i){
                for(int j = 1; j <= n; ++j){
                    if(c2[i][j] != '.')continue;
                    if((r[i] == n - 1) && (c[j] == n - 1))--s;
                }
            }
        }
        for(int i = 1; i <= n; ++i){
            c[i] = r[i] = r1[i] = c1[i] = 0;
        }
        if(cnt == inf){
            cout<<"Case #"<<i<<": "<<"Impossible\n";
            ++i;
            continue;
        }
        cout<<"Case #"<<i<<": "<<cnt<<" "<<s<<'\n';
        ++i;
    }


    return 0;
}
