#include<bits/stdc++.h>
using namespace std;


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

	
	void bfs(int src){
		queue<int>q;
		int dist[V]={-1};
		for(int i=0;i<=V;i++) dist[i]=-1;
		q.push(src);
		vector<bool>vis(V,false);
		dist[src]=0;
		while(!q.empty()){
			int node=q.front();
			q.pop();
			
			for(auto nbr: l[node]){
				if(dist[nbr]== -1){
					q.push(nbr);
					dist[nbr]=dist[node]+6;
					vis[nbr]=true;
				}
			}
		}

		for(int i=1;i<V;i++){
			if(i==src) continue;
			cout<<dist[i]<<" ";
		}
		cout<<"\n";
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

	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		Graph gr(n+1);
		
		while(m--){
			int u,v;
			cin>>u>>v;
			gr.addEdge(u,v);
		}
		int src;
		cin>>src;
		gr.bfs(src);

	}
	return 0;
}