#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

template<typename T>
class Graph{
	map<T,list<T>>l;

public:
	void addEdge(int x,int y){
		l[x].push_back(y);
		// l[y].push_back(x);
	}

	void dfs_helper(T src,map<int,bool>&vis){
		if(vis[src]) return;
		vis[src]=true;
		cout<<src<<" ";
		for(auto nbr:l[src]){
			dfs_helper(nbr,vis);
		}
	}

	void dfs(T src){
		map<int,bool>vis;
		for(auto p:l){
			T node=p.first;
			vis[node]=false;
		}
		dfs_helper(src,vis);
	}
};

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
	Graph<int> g;
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(3,0);


	g.dfs(0);
	return 0;
}