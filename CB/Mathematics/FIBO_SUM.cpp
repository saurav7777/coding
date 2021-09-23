#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll mod =1000000007;

ll k;
vector<ll>a,b,c;

vector<vector<ll>> multiply(vector<vector<ll>> A,vector<vector<ll>> B){
	vector<vector<ll>> C(3,vector<ll>(3));
	for(int i=1;i<=2;i++){
		for(int j=1;j<=2;j++){
			for(int x=1;x<=2;x++){
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

	//step 1
	vector<ll>F(3,0);
	F[1]=0;
	F[2]=1;

	//step 2 Transformation matrix
	vector<vector<ll>> T(3,vector<ll>(3));
	T[1][1]=0;
	T[1][2]=1;
	T[2][1]=1;
	T[2][2]=1;
	//cout<<T[1][1]<<" "<<T[1][2]<<" "<<T[2][1]<<" "<<T[2][2]<<"\n";
	//step 3 power of T
	T=pow(T,n);

	//cout<<T[1][1]<<" "<<T[1][2]<<" "<<T[2][1]<<" "<<T[2][2]<<"\n";
	//step 4 
	ll res=0;
	for(int i=1;i<=2;i++){
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
		ll n,m;
		cin>>n>>m;
		ll sn=solve(n+1)%mod;
		ll sm=solve(m+2)%mod;
		//cout<<sn<<" "<<sm<<"\n";
		cout<<(sm-sn + mod)%mod<<"\n";

		a.clear();
		b.clear();
		c.clear();

	}
	
	return 0;
}