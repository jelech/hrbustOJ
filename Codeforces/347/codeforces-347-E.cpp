#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i = a; i<n; i++)
#define per(i,a,n) for (int i = n-1; i>=a; i--)
#define pb push_back
#define mp make_pair
#define all(now) (now).begin(),(now).end()
#define fi first
#define se second
#define SZ(now) ((int)(now).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod = 1000000007;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
ll powmod(ll a,ll b,ll mod) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head
const int N = 1e6+7;
int a[N];
set<int> cur;
int n,x, y;
int input;
int main()
{
    scanf("%d", &n);
    rep(i,1,n+1){
        scanf("%d", &input);
        cur.insert(input);
    }
    scanf("%d%d", &x, &y);
    int ans = 0;
    set<int>::iterator it;
    while(x>y){
        int cnt = x - 1;
        // for(auto u:cur){
        // for (auto u = cur.begin(); u != cur.end();u++){
        for(it=cur.begin();it!=cur.end();){
            int u = *it;
            it++;
            if (x - (x % u) < y)
            {
                cur.erase(u);
            }
            else
                cnt = min(cnt, x - (x % u));
        }
        x = cnt;
        ans++;
    }
    printf("%d\n", ans);

    return 0;
}
/*

*/