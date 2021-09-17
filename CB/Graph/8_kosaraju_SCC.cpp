#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

void dfs(vector<int> gr[],int src,bool *vis,vector<int>&stack){
		vis[src]=true;
		for(auto nbr:gr[src]){
			if(!vis[nbr])
				dfs(gr,nbr,vis,stack);
		}

		stack.push_back(src);
}

void dfs2(vector<int> gr[],int src,bool *vis){
		vis[src]=true;
		cout<<src<<" ";
		for(auto nbr:gr[src]){
			if(!vis[nbr])
				dfs2(gr,nbr,vis);
		}
}

void SCC(vector<int> gr[],vector<int> rev_gr[],int n){
	bool vis[n]={0};
	vector<int>stack;

	// step 1. DO DFS and store nodes in stack acc to finish time
	for(int i=0;i<n;i++){
		if(!vis[i])
			dfs(gr,i,vis,stack);
	}

	//step 2. reverse a graph

	//step 3. do dfs acc to ordering in stack form last
	memset(vis,0,n);
	char component='A';
	for(int x=stack.size()-1;x>=0;x--){
		int node=stack[x];
		if(!vis[node]){
			cout<<component<<"--> ";
			dfs2(rev_gr,node,vis);
			cout<<"\n";
			component++;
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
	int n;
	cin>>n;
	vector<int> gr[n];
	vector<int> rev_gr[n];

	int m;
	cin>>m;
	while(m--){
		int x,y;
		cin>>x>>y;
		gr[x].push_back(y);
		rev_gr[y].push_back(x);
	}

	SCC(gr,rev_gr,n);
	return 0;
}