#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll mod =1000000000;

ll k;
vector<ll>a,b,c;

vector<vector<ll>> multiply(vector<vector<ll>> A,vector<vector<ll>> B){
	vector<vector<ll>> C(k+1,vector<ll>(k+1));
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			for(int x=1;x<=k;x++){
				C[i][j]=(C[i][j]+(A[i][x]*B[x][j])%mod)%mod;
			}
		}
	}
	return C;
}

vector<vector<ll>> pow(vector<vector<ll>> T,ll n){

	if(n==1){
		return T;
	}

	if(n&1){
		return multiply(T,pow(T,n-1));
	}
	vector<vector<ll>> v=pow(T,n/2);
	return multiply(v,v);
}

ll solve(ll n){
	if(n==0) return 0;
	if(n<=k) return b[n-1];

	//step 1
	vector<ll>F(k+1,0);
	for(int i=1;i<=k;i++){
		F[i]=b[i-1];
	}

	//step 2 Transformation matrix
	vector<vector<ll>> T(k+1,vector<ll>(k+1));
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			if(i<k){
				if(j==(i+1)){
					T[i][j]=1;
				}else{
					T[i][j]=0;
				}
			}else{
				T[i][j]=c[k-j];
			}
		}
	}

	//step 3 power of T
	T=pow(T,n-1);


	//step 4 
	ll res=0;
	for(int i=1;i<=k;i++){
		res=(res+ (T[1][i] * F[i])%mod)%mod;
	}
	return res;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
	ll t;
	cin>>t;
	while(t--){
		cin>>k;
		ll num;
		for(int i=0;i<k;i++){
			cin>>num;
			b.push_back(num);
		}
		for(int i=0;i<k;i++){
			cin>>num;
			c.push_back(num);
		}
		ll n;
		cin>>n;
		cout<<solve(n)<<"\n";
		a.clear();
		b.clear();
		c.clear();

	}
	
	return 0;
}