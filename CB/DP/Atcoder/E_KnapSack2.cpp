#include<bits/stdc++.h>
using namespace std;

#define inf 1000000008;
typedef long long int ll;
int w[1001];
int v[1001];

ll n,wt;


int knapsack2(){
	int maxval=n*1000;
	// cout<<maxval<<"\n";
	ll dp[n+1][maxval+1];

	for(int i=0;i<=maxval;i++){
		dp[1][i]=inf;
	}

	dp[1][0]=0;
	dp[1][v[1]]=w[1];

	ll ans=0;
	for(int i=2;i<=n;i++){
		for(int val=1;val<=maxval;val++){
			if(val>=v[i]){
				dp[i][val]=min(dp[i-1][val],w[i]+dp[i-1][val-v[i]]);
			}else
				dp[i][val]=dp[i-1][val];
			
		}
	}

	for(int i=0;i<=maxval;i++){
		if(dp[n][i]<=wt) ans=i;
	}
	
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../../input.txt","r",stdin);
	freopen("../../output.txt","w",stdout);
#endif
	
	
	cin>>n>>wt;
	// cout<<wt<<"\n";
	for(int i=1;i<=n;i++){
		cin>>w[i];
		cin>>v[i];
	}

	cout<<knapsack2()<<"\n";
}