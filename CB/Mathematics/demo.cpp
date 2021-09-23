
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=1000000007;
ll size=200002;
ll fact[200002],inv[200002];

ll solve(ll n,ll k){
	return ((fact[n]%mod * inv[n-k]%mod)%mod * inv[k]%mod)%mod;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input1.txt","r",stdin);
	freopen("output1.txt","w",stdout);
#endif
	// fact[0]=inv[0]=inv[1]=1;
	// for(ll i=1;i<size;i++){
	// 	fact[i]=(fact[i-1]* i)%mod;
	// }
	// for(ll i=2;i<size;i++){
	// 	inv[i]=((mod - mod/i)*(inv[mod%i]%mod))%mod; 
	// }

	// for(ll i=1;i<size;i++){
	// 	inv[i]=(inv[i-1] * inv[i])%mod;
	// }
	ll n=0,m=0;
	cin>>n>>m;
	ll a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	while(m--){
		ll l=0,r=0,k=0;
		cin>>l>>r>>k;
		// for(int j=l;j<=r;j++){
		// 	a[j-1]=(a[j-1]+solve(j-l+k,k))%mod;
		// }
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}