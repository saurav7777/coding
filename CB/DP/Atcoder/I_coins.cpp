#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll mod=1000000007;
double dp[3001][3001]={-1};
double arr[3001];
ll n;

double solve(int i,int x){
	if(x==0) return 1;
	if(i==0) return 0;
	if(dp[i][x] > -0.9) return dp[i][x];
	dp[i][x]=arr[i]*solve(i-1,x-1) + (1-arr[i])*solve(i-1,x);
	return dp[i][x];

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../../input.txt","r",stdin);
	freopen("../../output.txt","w",stdout);
#endif
	
	cin>>n;
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++) cin>>arr[i];
	solve(n,(n+1)/2);
	cout<<fixed<<setprecision(10)<<dp[n][(n+1)/2];

}









