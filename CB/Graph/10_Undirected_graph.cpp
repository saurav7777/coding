// Bipartite graph check
// shortest cycle in graph


#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

class Graph{
	int V;
	list<int>*l;

public:
	Graph(int v){
		this->V=v;
		l=new list<int>[v];
	}
	void addEdge(int x,int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}

	bool dfs_helper(int src,int *vis,int parent,int color){
		vis[src]=color;
		
		for(auto nbr:l[src]){
			if(vis[nbr]==0){
				bool subprob = dfs_helper(nbr,vis,src,3-color);
				if(subprob==false) return false;
			}else if(nbr!=parent && color==vis[nbr])
				return false;
		}
		return true;
	}

	bool dfs(int src){
		int *vis= new int[V];
		// 0-not visited 1-color1 2-color2

		for(int i=0;i<V;i++){
			vis[i]=0;
		}

		bool ans=false;

		ans=dfs_helper(0,vis,0,1);
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

	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,0);

	if(g.dfs(0)) cout<<"partite";
	else cout<<"Not partite";
	return 0;
}