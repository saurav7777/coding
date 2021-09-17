#include<bits/stdc++.h>
using namespace std;

const int n=100005,m=22;

vector<int>gr[n];
int Par[n],dep[n];

void dfs(int curr,int par){
	Par[curr]=par;
	for(auto x:gr[curr]){
		if(x!=par){
			dep[x]=dep[curr]+1;
			dfs(x,curr);
		}
	}
}

int lca_brute(int x,int y){
	if(x==y) return x;

	// dx should be at greater depth
	if(dep[x]<dep[y]) swap(x,y);

	while(dep[x]>dep[y]){
		x=Par[x];
	}

	while(x!=y){
		x=Par[x];
		y=Par[y];
	}
	return x;
}

void solve(int n){
	//root as 1
	dfs(1,0);

	// for(int i=0;i<=n;i++){
	// 	cout<<i<<" "<<dep[i]<<"-->"<<Par[i]<<"\n";
	// }

	cout<<lca_brute(13,16)<<"\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif

	int n,e;
	cin>>n>>e;
	for(int i=0;i<e;i++){
		int x,y;
		cin>>x>>y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	
	solve(n);

	return 0;
}