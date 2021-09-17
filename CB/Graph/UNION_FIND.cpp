#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

class Graph{
	int v;
	list<pair<int,int>>l;
public:
	Graph(int v){
		this->v=v;
	}

	void addEdge(int u,int v){
		l.push_back({u,v});
	}

	int find(int i,int parent[]){
		if(parent[i] == -1) return i;
		return parent[i]= find(parent[i],parent);
	}

	void Union(int a,int b,int parent[],int rank[]){
		int s1=find(a,parent);
		int s2=find(b,parent);
		if(s1!=s2){
			if(rank[s1]<rank[s2]){
				parent[s1]=s2;
				rank[s2]+=rank[s1];
			}else{
				parent[s2]=s1;
				rank[s1]+=rank[s2];
			}
		}
	}

	bool contains_cycle(){
		//DSU logic
		int parent[v]={-1};
		int *rank= new int[v];
		for(int i=0;i<v;i++){
			parent[i]= -1;
			rank[i]=1;
		}
		for(auto edge:l){
			int u=edge.first;
			int v=edge.second;

			int s1=find(u,parent);
			int s2=find(v,parent);
			cout<<u<<"-->"<<s1<<" "<<v<<"-->"<<s2<<"\n";
			if(s1!=s2){
				Union(s1,s2,parent,rank);
			}else return true;
		}
		// delete [] parent;
		return false;
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
	gr.addEdge(0,1);
	gr.addEdge(1,2);
	gr.addEdge(2,3);
	// gr.addEdge(3,0);
	if(gr.contains_cycle()) cout<<"contains_cycle";
	else cout<<"cycle nahi mila";

	return 0;
}