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

ll c[100], mx[100];
vector<int> v[100];
bool vis[100];

void dfs(int x, ll sum, int pos){
    if(vis[x])return;
    vis[x] = 1;
    if(v[x].size() == 1){
        mx[pos] = max(mx[pos], sum);
        return;
    }
    for(auto u:v[x]){
        dfs(u, sum + c[u], pos);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(15);

    
    int test = 1;
    int p = 1;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        for(int i = 1; i <= n; ++i){
            cin>>c[i];
            vis[i] = 0;
        }
        for(int i = 1; i < n; ++i){
            int x, y;cin>>x>>y;
            v[x].pb(y);
            v[y].pb(x);
        }
        int u = v[1].size();
        vis[1] = 1;
        for(int i = 0; i < u; ++i){
            dfs(v[1][i], c[v[1][i]], i);
        }
        sort(mx, mx + u);
        int cnt = mx[u - 1] + c[1];
        if(u > 1){
            cnt += mx[u - 2];
        }
        cout<<"Case #"<<p<<": "<<cnt<<'\n';
        ++p;
        for(int i = 1; i <= n; ++i){
            v[i].clear();
            mx[i - 1] = mx[i] =  0;
        }
    }


    return 0;
}
