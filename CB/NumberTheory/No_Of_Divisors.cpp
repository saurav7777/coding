#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int mod =1000000007;
vector<ll>primes;

bitset<1000006>b;
map<ll,ll>mp;
void sieve(){
	b.set();
	b[0]=b[1]=0;
	b[2]=1;
	for(ll i=2;i<=1000005;i++){
		if(b[i]){
			primes.push_back(i);
			for(ll j=i*i;j<=1000005;j+=i){
				b[j]=0;
			}
		}
	}
}

ll solve(ll n){
	ll ans=1;
	ll p=primes[0];
	int i=0;
	while(p*p <=n){
		if(n%p == 0){
			int cnt=0;
			while(n%p == 0){
				cnt++;
				n/=p;
			}
			mp[p]+=cnt;
		}
		i++;
		p=primes[i];
	}
	if(n>1){
		mp[n]+=1ll;
	}
	return ans%mod;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
	sieve();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll ans=1l,temp=1;
		for(int i=0;i<n;i++){
			ll num=1;
			cin>>num;
			//temp=temp*num;
			ll temp=solve(num);
		}
		for(auto it:mp){
			ans=(ans*(it.second +1ll))%mod;
		}
		mp.clear();
		cout<<ans<<"\n";
	}
	return 0;
}