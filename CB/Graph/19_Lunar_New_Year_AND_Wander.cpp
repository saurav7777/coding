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
	
	void solve(){
		vector<int>ans;
		set<int>can;
		vector<bool>vis(V,0);

		// ans.push_back(1);
		vis[1]=true;
		can.insert(1);
		while(!can.empty()){
			// int i=ans.back();
			auto i= *(can.begin());
			ans.push_back(i);
			vis[i]=true;
			can.erase(i);
			// cout<<i<<" ";
			for(int nbr:l[i]){
				if(!vis[nbr])
					can.insert(nbr);
			}

		}

		for(auto x:ans){
			cout<<x<<" ";
		}
		return;
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


	int n,m;
	cin>>n>>m;
	Graph gr(n+1);
	while(m--){
		int u,v;
		cin>>u>>v;
		gr.addEdge(u,v);

	}
	gr.solve();

	return 0;
}