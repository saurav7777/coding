#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll dp[100005];

ll mincost(ll arr[],ll n){
	dp[0]=0;
	dp[1]=0;
	dp[2]=abs(arr[2]-arr[1]);
	for(int i=3;i<=n;i++){
		dp[i]+=min((ll)abs(arr[i]-arr[i-1])+dp[i-1],(ll)abs(arr[i]-arr[i-2])+dp[i-2]);
	}
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
	
	int n;
	cin>>n;
	ll arr[n+1];
	arr[0]=0;
	for(int i=1;i<=n;i++) cin>>arr[i];
	cout<<mincost(arr,n)<<"\n";
}