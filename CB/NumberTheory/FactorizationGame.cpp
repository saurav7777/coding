#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll p[1000005]={1};
map<ll,ll>mp;

void sieve(){
	p[0]=p[1]=1;
	p[2]=2;
	for(int i=2;i<1000005;i++){
		p[i]=i;
	}
	for(ll i=2;i<1000005;i++){
		if(p[i]==i){
			for(ll j=2*i;j<1000005;j=j+i){
				if(p[j]==j)
					p[j]=i;
			}
		}	
	}
}

vector<ll> getfactors(ll n){
	vector<ll>pr;
	ll temp=n;
	while(temp!=1ll){
		ll v=p[temp];
		if(v!=1ll){
			pr.push_back(v);
		}
		while(temp%v == 0) temp=temp/v;
		//temp=temp/v;
	}
	return pr;	
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
	vector<ll>pr;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		
		for(int i=0;i<n;i++){
			ll num;
			cin>>num;
			if(num==1) continue;
			pr=getfactors(num);
			for(ll x:pr){
				//cout<<x<<" ";
				mp[x]++;
			}
		}

		ll count=mp.size();
		//cout<<count<<" ";
		if(count%2) cout<<"Mancunian\n";
		else cout<<"Liverbird\n";
		mp.clear();
		//fill(cnt.begin(),cnt.end(),0);
	}
}