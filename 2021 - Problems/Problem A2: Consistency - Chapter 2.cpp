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
const ll maxn = 1e5 + 2;

vector<int> v[40];
int dist[40][40];

void dfs(int x, int y, int d){
    dist[x][y] = d;
    for(auto u:v[y]){
        if(d + 1 < dist[x][u])dfs(x, u, d + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(15);

    
    int test = 1;
    cin>>test;
    int i = 1;
    while(test--){
        string s;cin>>s;
        int n = s.size();
        int k;cin>>k;
        for(int j = 1; j <= k; ++j){
            char a, b;
            cin>>a>>b;
            v[int(a - 'A')].pb(int(b - 'A'));
        }
        for(int j = 0; j <= 30; ++j){
            for(int t = 0; t <= 30; ++t){
                dist[j][t] = inf;
            }
        }
        int cnt = inf;
        for(int j = 'A'; j <= 'Z'; ++j){
            dfs(j - 'A', j - 'A', 0);
        }
        for(int j = 'A'; j <= 'Z'; ++j){
            int sum = 0;
            for(int t = 0; t < n && sum >= 0; ++t){
                if(dist[s[t] - 'A'][j - 'A'] == inf){
                    sum = -1;
                }
                else{
                    sum += dist[s[t] - 'A'][j - 'A'];
                }
            }
            if(sum < 0)continue;
            cnt = min(cnt, sum);
        }
        if(cnt == inf)cnt = -1;
        cout<<"Case #"<<i<<": "<<cnt<<'\n';
        for(int i = 0; i <= 28; ++i){
            v[i].clear();
        }
        ++i;
    }


    return 0;
}
