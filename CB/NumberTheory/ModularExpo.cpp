#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll p[1000005]={1};
ll x,y,g;

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
		//while(temp%v == 0) temp=temp/v;
		temp=temp/v;
	}
	return pr;	
}

void extgcd(ll a,ll b){
    if(b==0){
        x=1ll;
        y=0ll;
        g=a;
        return ;
    }
    extgcd(b,a%b);
    //cout<<x<<" "<<y<<"\n";
    ll x1=y;
    ll y1=x - (a/b)*y;
    x=x1;
    y=y1;
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
	ll a,b,c;
	cin>>a>>b>>c;
	vector<ll>num=getfactors(c);

	//cout<<powmod(2,5,5);

	vector<ll>rem;
	ll prod=1ll;
	int size=num.size();
	for(ll x:num){
		//cout<<x<<" ";
		ll temp=powmod(a,b,x);
		//cout<<temp<<" ";
		rem.push_back(temp%x);
		prod*=x;
	}
	//cout<<"\n";
	ll ans=0ll;
	// cout<<size<<" ";
	for(int i=0;i<size;i++){
		ll pp=c/num[i];
		extgcd(pp,num[i]);
		x=(x+num[i])%num[i];
		//x=powmod(pp,num[i]-2ll,num[i]);
		
		ans=(ans%c +(rem[i]*pp*x)%c)%c;
	}
	if(c==1){
		ans=0;
	}
	cout<<ans<<"\n";
}