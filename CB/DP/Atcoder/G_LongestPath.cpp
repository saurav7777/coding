#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector<int>gr[100005];
vector<bool>vis(100005,0);
int dp[100005]={0};

int ans=0;

int solve(int src){
	if(vis[src]) return dp[src];
	vis[src]=true;
	int len=0;
	for(auto x:gr[src]){
		len=max(len,1+solve(x));		
	}
	ans=max(len,ans);
	return dp[src]=len;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../../input.txt","r",stdin);
	freopen("../../output.txt","w",stdout);
#endif
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		gr[x].push_back(y);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
			solve(i);
	cout<<ans<<"\n";
}









