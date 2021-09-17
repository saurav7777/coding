#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

class Graph{
	int V;
	list<pair<int,int>>*l;

public:
	Graph(int v){
		this->V=v;
		l=new list<pair<int,int>>[v];
	}
	void addEdge(int x,int y,int cost){
		l[x].push_back({y,cost});
		l[y].push_back({x,cost});
	}

	int dfs_helper(int src,bool *vis,int *count,int &ans){
		vis[src]=true;
		count[src]=1;
		for(auto nbr_pair:l[src]){
			int nbr=nbr_pair.first;
			int wt=nbr_pair.second;
			if(!vis[nbr]){
				count[src]+=dfs_helper(nbr,vis,count,ans);

				int nx=count[nbr];
				int ny=V-nx;
				ans+= 2*min(nx,ny)*wt;
			}
		}
		return count[src];
	}

	int dfs(int src){
		bool *vis= new bool[V];
		int *count=new int[V];

		for(int i=0;i<V;i++){
			count[i]=0;
			vis[i]=false;
		}

		int ans=0;

		dfs_helper(0,vis,count,ans);
		return ans;
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

	Graph g(4);
	g.addEdge(0,1,3);
	g.addEdge(1,2,2);
	g.addEdge(2,3,2);


	cout<<g.dfs(0)<<"\n";
	return 0;
}