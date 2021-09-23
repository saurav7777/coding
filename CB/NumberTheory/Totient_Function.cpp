#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll p[1000005]={1};

vector<int> phi(1000005);

void phi_1_to_n(int n) {
    
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}

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
	//cout<<temp<<" "<<p[temp]<<" ";
	while(temp!=1){
		ll v=p[temp];
		if(v!=1){
			pr.push_back(v);
		}
		while(temp%v == 0) temp=temp/v;
	//	cout<<temp<<" ";
	}
	// for(int i:pr){
	// 	cout<<i<<" ";
	// }
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
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll>pr=getfactors(n);
		ll ans=n-1;
		for(ll it:pr){
			ans-=ans/it;
		}
		if(n==1) ans=1;
		cout<<ans<<"\n";
	}
	//cout<<p[8];
	//getfactors(24);

}