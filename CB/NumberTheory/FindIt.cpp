#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cnt[100005]={0};
ll sum[100005]={0};
bitset<1000006>b;

void sieve(){

	for(ll i=2;i<100005;i++){
			for(ll j=i;j<100005;j+=i){
				sum[i]+=cnt[j];
			}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
	for(int i=0;i<100005;i++){
		cnt[i]=0;
		sum[i]=0;
	}
	ll n;
	cin>>n;
	//vector<ll>v(n+1);
	for(ll i=0;i<n;i++){
		ll num;
		cin>>num;
		++cnt[num];
		//cout<<v[i]<<" "<<cnt[v[i]]<<"\n";
	}
	sieve();
	ll q;
	cin>>q;
	while(q--){
		ll k;
		cin>>k;
		cout<<sum[k];
		if(q>0){
			cout<<"\n";
		}

	}
	return 0;
}