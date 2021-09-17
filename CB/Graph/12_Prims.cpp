#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

class Graph{
	vector<pair<int,int>> *l;
	int v;
public:
	Graph(int v){
		this->v=v;
		l=new vector<pair<int,int>>[v];
	}

	void addEdge(int x,int y,int cost){
		l[x].push_back({y,cost});
		l[y].push_back({x,cost});
	}

	int prim_mst(){
		//min heap
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
		//visited array for node in MST set or not
		bool* vis = new bool[v]{0};

		int ans=0;

		q.push({0,0}); //weight and node
		while(!q.empty()){
			// pick out edge with min weight
			auto best=q.top();
			q.pop();

			int to= best.second;
			int weight= best.first;
			// cout<<to<<" "<<weight<<"\n";
			if(vis[to]){
				//discard 
				continue;
			}
			//otherwise take the current edge
			ans+=weight;
			vis[to]=1;
			for(auto p:l[to]){
				if(vis[p.first]==0){
					q.push({p.second,p.first});
				}
			}
		}
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

	Graph gr(4);
	gr.addEdge(0,1,1);
	gr.addEdge(1,1,3);
	gr.addEdge(2,0,2);
	gr.addEdge(3,2,4);
	gr.addEdge(0,3,2);
	gr.addEdge(1,2,2);
	cout<<gr.prim_mst();
	return 0;
}