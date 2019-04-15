#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i = a; i<n; ++i)
#define per(i,a,n) for (int i = n-1; i>=a; --i)
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
int a[N];

VI solve(const string& s)
{
    int len = s.length();
    VI ret(len + 1);
    rep(i,0,len) {
        ret[i + 1] = s[i] - 'a';
    }
    return ret;
}

int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    string ch1, ch2;
    cin >> ch1 >> ch2;
    VI a = solve(ch1), b = solve(ch2);
    int len = ch1.length();
    per(i, 0, len + 1) {
        a[i] += b[i];
        if(i){
            a[i - 1] += a[i] / 26;
            a[i] %= 26;
        }
    }
    rep(i, 0, len + 1) {
        int rem = a[i] % 2;
        a[i] /= 2;
        if(i + 1 <= len) {
            a[i + 1] += rem * 26;
        }
    }

    rep(i, 1, len + 1) {
        cout << char(a[i] + 'a');
    }
    cout << endl;


    return 0;
}
/*

*/