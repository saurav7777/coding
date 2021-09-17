#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

class DSU{
	int *parent;
	int *rank;
public:
	DSU(int n){
		parent=new int[n];
		rank=new int[n];
		for(int i=0;i<n;i++){
			parent[i]=-1;
			rank[i]=1;
		}
	}

	int find(int i){
		if(parent[i]== -1) return i;
		return parent[i]=find(parent[i]);
	}

	void Union(int a,int b){
		int pa=find(a);
		int pb=find(b);
		if(pa!=pb){
			if(rank[pa]<rank[pb]){
				parent[pa]=pb;
				rank[pb]+=pa;
			}else{
				parent[pb]=pa;
				rank[pa]+=pb;
			}
		}
	}
};


class Graph{
	vector<vector<int>> egdelist;
	int v;
public:
	Graph(int v){
		this->v=v;
	}

	void addEdge(int x,int y,int cost){
		egdelist.push_back({cost,x,y});
	}

	int kruksal_mst(){
		sort(egdelist.begin(),egdelist.end());
		int ans=0;
		DSU s(v);

		for(auto p:egdelist){
			int w=p[0];
			int x=p[1];
			int y=p[2];
	
			if(s.find(x)!=s.find(y)){
				s.Union(x,y);
				ans+=w;
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
	cout<<gr.kruksal_mst();
	return 0;
}