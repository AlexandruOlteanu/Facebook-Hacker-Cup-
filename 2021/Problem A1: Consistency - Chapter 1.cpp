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

int v[100];

bool check(char c){
    string t = "AEIOU";
    int u = t.find(c);
    if(u >= 0 && u <= 4)return 1;
    return 0;
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
        int a = 0, b = 0;
        for(int i = 0; i < n; ++i){
            ++v[s[i] - 'A'];
            if(check(s[i]))++a;
            else ++b;
        }
        int cnt = inf;
        for(int i = 'A'; i <= 'Z'; ++i){
            int sum = 0;
            if(check(char(i))){
                sum += b;
                sum += 2 * (a - v[i - 'A']);
            }
            else{
                sum += a;
                sum += 2 * (b - v[i - 'A']);
            }
            cnt = min(cnt, sum);
            v[i - 'A'] = 0;
        }
        cout<<"Case #"<<i<<": "<<cnt<<'\n';
        ++i;
    }


    return 0;
}
