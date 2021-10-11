#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll dp[101][100005]={0};
int w[1001];
int v[1001];

int n,wt;

ll knapsack1(int i,int W){
	if(i>n) return 0;
	if(W<=0) return 0;
	if(dp[i][W]) return dp[i][W];

	ll ans=0;
	ll temp=0;
	if(w[i]<=W){
		temp=v[i]+knapsack1(i+1,W-w[i]);
		// cout<<"temp-->"<<temp<<"\n";
	}
	ans+=max(temp,knapsack1(i+1,W));
	// cout<<"ans-->"<<ans<<"\n";
	return dp[i][W]=ans;
}

ll knapsack2(){
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=wt;j++){
			if(j>=w[i])
				dp[i][j]=max(dp[i-1][j],v[i]+dp[i-1][j-w[i]]);
			else 
				dp[i][j]=dp[i-1][j];
		}
	}
	
	return ans=dp[n][wt];
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