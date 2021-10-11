#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll dp[100005];

ll mincost(ll arr[],ll n,ll k){
	dp[0]=0;
	dp[1]=0;
	for(int i=2;i<=n;i++){
		ll ans=INT_MAX;
		for(int j=1;j<=k;j++){
			if(j<i)
				ans=min(ans,(ll)abs(arr[i]-arr[i-j])+dp[i-j]);
		}
		dp[i]=ans;
	}

	for(int i=1;i<=n;i++) cout<<dp[i]<<" ";
	cout<<"\n";
	return dp[n];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../../input.txt","r",stdin);
	freopen("../../output.txt","w",stdout);
#endif
	
	int n,k;
	cin>>n>>k;
	ll arr[n+1];
	arr[0]=0;
	for(int i=1;i<=n;i++) cin>>arr[i];
	cout<<mincost(arr,n,k)<<"\n";
}