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
const int N = 1e5+7;
int T,n,m;
int num[17];

int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    for (int i = 0; i < 14; i++) scanf("%d", num + i);
    long long ans = 0, sum = 0;
    for (int i = 0, pre, tmp, left; i < 14; i++, sum = 0) {
        if (num[i]) {
            pre = num[i], tmp = num[i] / 14, left = num[i] % 14, num[i] = 0;
            for (int j = 1; j <= left; j++) {
                int cur = (j + i) % 14;
                if ((num[cur] + tmp + 1) % 2 == 0) {
                    sum += num[cur] + tmp + 1;
                }
            }
            for (int j = left + 1; j <= 14; j++) {
                int cur = (j + i) % 14;
                if ((num[cur] + tmp) % 2 == 0) {
                    sum += num[cur] + tmp;
                }
            }
            num[i] = pre;
            ans = std::max(ans, sum);
        }
    }
    printf("%lld\n", ans);
    return 0;
}

/*
0 2 2 2 2 1 0 0 0 0 0 0 0 0
*/