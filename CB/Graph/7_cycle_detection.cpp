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

	bool cycle_helper(T src,map<int,bool>&vis,map<int,bool>&lookup){
		vis[src]=true;
		lookup[src]=true;
		//cout<<src<<" ";
		for(auto nbr:l[src]){
			if(vis[nbr]==false){
				// return cycle_helper(nbr,vis,lookup);
				bool cycle_mila=cycle_helper(nbr,vis,lookup);
				if(cycle_mila) return true;
			}else if(lookup[nbr]==true)
				return true;
		}

		//leave a node
		lookup[src]=false;
		return false;
	}

	bool cycle_detecter(){
		map<int,bool>vis;
		map<int,bool>lookup;
		for(auto p:l){
			T node=p.first;
			vis[node]=false;
			lookup[node]=false;
		}
		return cycle_helper(0,vis,lookup);
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
	g.addEdge(4,2);
	g.addEdge(4,5);
	g.addEdge(1,5);
	g.addEdge(5,6);

	if(g.cycle_detecter()) cout<<"cycle mil gya";
	else cout<<"cycle nhi mila";
	return 0;
}