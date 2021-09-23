#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod=1000000007ll;

ll powmod(ll a, ll b,ll c){
	ll ans=1ll;
	a%=c;
	while(b){
		if(b&1ll){
			ans=(ans*a)%c;
		}
		a=(a*a)%c;
		b=b>>1ll;
	}
	return ans%c;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
	ll n,r;
	cin>>n>>r;
	ll ans=1ll,f1=1ll,f2=1ll;
	for(ll i=2;i<=n;i++){
		ans=(ans*i)%mod;
	}

	for(ll i=2;i<=n-r;i++){
		f1=(f1*i)%mod;
	}
	for(ll i=2;i<=r;i++){
		f2=(f2*i)%mod;
	}
	ll inv1=powmod(f1,mod-2,mod)%mod;
	ll inv2=powmod(f2,mod-2,mod)%mod;
	ans=((ans%mod * inv1%mod)%mod *inv2%mod)%mod;
	cout<<ans<<"\n";
}