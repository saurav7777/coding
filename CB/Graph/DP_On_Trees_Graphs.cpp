#include<bits/stdc++.h>
using namespace std;

#define INF 100000
typedef long long int ll;

const int n=100;

vector<int>gr[n];
int dp[n];
int vis[n]={0};
int depth[n];

// smallest node in subtree of node x
void dfs(int curr,int par){
	dp[curr]=curr;
	for(auto x:gr[curr]){
		if(x!=par){
			dfs(x,curr);
			dp[curr]=min(dp[curr],dp[x]);
		}
	}
}

// samllest height of node that can be visited from subtree of node x
void dp_graph(int curr,int par,int height){
	vis[curr]=1;
	dp[curr]=height;
	depth[curr]=height;
	for(auto x:gr[curr]){
		if(vis[x]==0){
			dp_graph(x,curr,height+1);
			dp[curr]=min(dp[curr],dp[x]);
		}else if(x != par){
			//backedge
			dp[curr]=min(dp[curr],depth[x]);

		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif

	int n,m;
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		vis[i]=0;
	}
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	// dfs(1,0);
	dp_graph(1,0,0);
	for(int i=1;i<=n;i++){
		cout<<i<<"-->"<<dp[i]<<"\n";
	}
	
	
	return 0;
}