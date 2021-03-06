// F
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

namespace polysum {
	const int D=101000;
	ll a[D],f[D],g[D],p[D],p1[D],p2[D],b[D],h[D][2],C[D];
	ll calcn(int d,ll *a,ll n) {
		if (n<=d) return a[n];
		p1[0]=p2[0]=1;
		rep(i,0,d+1) {
			ll t=(n-i+mod)%mod;
			p1[i+1]=p1[i]*t%mod;
		}
		rep(i,0,d+1) {
			ll t=(n-d+i+mod)%mod;
			p2[i+1]=p2[i]*t%mod;
		}
		ll ans=0;
		rep(i,0,d+1) {
			ll t=g[i]*g[d-i]%mod*p1[i]%mod*p2[d-i]%mod*a[i]%mod;
			if ((d-i)&1) ans=(ans-t+mod)%mod;
			else ans=(ans+t)%mod;
		}
		return ans;
	}
	void init(int M) {
		f[0]=f[1]=g[0]=g[1]=1;
		rep(i,2,M+5) f[i]=f[i-1]*i%mod;
		g[M+4]=powmod(f[M+4],mod-2);
		per(i,1,M+4) g[i]=g[i+1]*(i+1)%mod;
	}
	ll polysum(ll n,ll *a,ll m) { // a[0].. a[m] \sum_{i=0}^{n-1} a[i]
		a[m+1]=calcn(m,a,m+1);
		rep(i,1,m+2) a[i]=(a[i-1]+a[i])%mod;
		return calcn(m+1,a,n-1);
	}
	ll qpolysum(ll R,ll n,ll *a,ll m) { // a[0].. a[m] \sum_{i=0}^{n-1} a[i]*R^i
		if (R==1) return polysum(n,a,m);
		a[m+1]=calcn(m,a,m+1);
		ll r=powmod(R,mod-2),p3=0,p4=0,c,ans;
		h[0][0]=0;h[0][1]=1;
		rep(i,1,m+2) {
			h[i][0]=(h[i-1][0]+a[i-1])*r%mod;
			h[i][1]=h[i-1][1]*r%mod;
		}
		rep(i,0,m+2) {
			ll t=g[i]*g[m+1-i]%mod;
			if (i&1) p3=((p3-h[i][0]*t)%mod+mod)%mod,p4=((p4-h[i][1]*t)%mod+mod)%mod;
			else p3=(p3+h[i][0]*t)%mod,p4=(p4+h[i][1]*t)%mod;
		}
		c=powmod(p4,mod-2)*(mod-p3)%mod;
		rep(i,0,m+2) h[i][0]=(h[i][0]+h[i][1]*c)%mod;
		rep(i,0,m+2) C[i]=h[i][0];
		ans=(calcn(m,C,n)*powmod(R,n)-c)%mod;
		if (ans<0) ans+=mod;
		return ans;
	}
}

ll mul(ll a,ll b,ll c) {
	a%=mod; b%=mod; c%=mod;
	return a*b%mod*c%mod;
}

const int N=20100;
int n,x,pos[N],_;
pair<int,int> p[N];
ll a,b,fl[N],fr[N],s[N];
void solve() {
	scanf("%d%lld%lld",&n,&a,&b);
	rep(i,0,n) {
		scanf("%d",&x);
		p[i]=mp(x,i); 
	}
	ll ret=0;
	sort(p,p+n);
	rep(rem,0,n) {
		int t=0;
		rep(i,0,n) if (p[i].fi%n==rem) pos[t++]=p[i].se-(p[i].fi-rem);
		sort(pos,pos+t);
		rep(i,0,t) {
			fl[i]=(a-pos[i]+n-1)/n;
			fr[i]=(b-pos[i])/n;
//			printf("%d %lld %lld\n",i,fl[i],fr[i]);
		}
		rep(i,0,t) if (fl[i]<=fr[i]) {
			rep(pl,0,5) {
				ll x=fl[i]+pl;
				s[pl]=mul(rem+x*n,(pos[i]+x*n)-a+1,b-(pos[i]+x*n)+1);
				if (pl>0) s[pl]=(s[pl]+s[pl-1])%mod;
				if (s[pl]<0) s[pl]+=mod;
			}
			ret=(ret+polysum::calcn(4,s,fr[i]-fl[i]))%mod;
//			printf("%d %d %lld\n",i,i,polysum::calcn(4,s,fr[i]-fl[i]));
		}
		rep(i,0,t) rep(j,i+1,t) if (max(fl[i],fl[j])<=min(fr[i],fr[j])) {
			ll l=max(fl[i],fl[j]),r=min(fr[i],fr[j]);
			rep(pl,0,5) {
				ll x=l+pl;
				s[pl]=mul(2*(rem+x*n),(pos[i]+x*n)-a+1,b-(pos[j]+x*n)+1);
				if (pl>0) s[pl]=(s[pl]+s[pl-1])%mod;
				if (s[pl]<0) s[pl]+=mod;
			}
			ret=(ret+polysum::calcn(4,s,r-l))%mod;
//			printf("%d %d %lld\n",i,j,polysum::calcn(4,s,r-l));
		}
	}
	printf("%lld\n",ret);
}
int main() {
	polysum::init(10);
	for (scanf("%d",&_);_;_--) solve();
}
