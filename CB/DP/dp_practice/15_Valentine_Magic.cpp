#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000000009ll
typedef long long ll;

ll dp[101][101];

int mod =1000003;

ll n,m;
vector<ll>b(100,0);
vector<ll>g(100,0);

ll solve(int i,int j){
	if(i==n) return 0; // paired all the boys

	if(j==m){
		//we have rejected all the girls
		return INF;
	}

	if(dp[i][j]!= -1) return dp[i][j];

	ll op1=abs(b[i]-g[j]) + solve(i+1,j+1);
	ll op2=solve(i,j+1);
	dp[i][j]=min(op1,op2);
	return min(op1,op2);
}



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif

	for(int i=0;i<=100;i++){
		for(int j=0;j<=100;j++){
			dp[i][j]= -1;
		}
	}

	cin>>n>>m;
	cout<<n<<" "<<m<<"\n";
	for(int i=0;i<n;i++) cin>>b[i];
	for(int i=0;i<m;i++) cin>>g[i];

	cout<<solve(0,0)<<"\n";
	// for(int i=0;i<=n;i++){
	// 	for(int j=0;j<=m;j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
}