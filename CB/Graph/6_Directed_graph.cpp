#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

template<typename T>
class Graph{
	map<T,list<T>>l;

public:
	void addEdge(T x,T y){
		l[x].push_back(y);
		// l[y].push_back(x);
	}

	void bfs_topo(){
		map<T,int>indegree;
		for(auto p:l){
			T node=p.first;
			indegree[node]=0;
		}

		//update the indegree
		for(auto p:l){
			T node=p.first;
			for(auto nbr:p.second){
				indegree[nbr]++;
			}
		}

		//bfs
		//1.find nodes with 0 indegree
		queue<T>q;
		for(auto x:indegree){
			if(x.second==0){
				q.push(x.first);
			}
		}

		//2.start removing element from queue
		while(!q.empty()){
			T node =q.front();
			q.pop();
			cout<<node<<"\n";

			//iterate over neighbours and reduced the indegree
			for(auto nbr:l[node]){
				indegree[nbr]--;
				if(indegree[nbr]==0) 
					q.push(nbr);
			}
		}
	}
	void dfs_helper(T src,map<T,bool>&vis,list<T>&ordering){
		// mark the node visited
		vis[src]=true;

		// call DFS on all neighbours
		for(auto nbr:l[src]){
			if(vis[nbr]==false)
				dfs_helper(nbr,vis,ordering);
		}

		// for topo sort
		ordering.push_front(src);
	}

	void dfs_Topo(){
		map<T,bool>vis;
		list<T>ordering;
		for(auto p:l){
			T node=p.first;
			vis[node]=false;
		}

		//call the helper function
		for(auto p:l){
			T node=p.first;
			if(vis[node]==false)
				dfs_helper(node,vis,ordering);
		}

		// print the ordering list
		for(auto x:ordering){
			cout<<x<<"\n";
		}
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
	Graph<string> g;
	g.addEdge("python","Data Processing");
	g.addEdge("python","Pytorch");
	g.addEdge("python","ML basics");
	g.addEdge("Pytorch","Deep Learning");
	g.addEdge("ML basics","Deep Learning");
	g.addEdge("Deep Learning","Face Recog");
	g.addEdge("Data set","Face Recog");

	g.dfs_Topo();
	cout<<" \nBFS \n";
	g.bfs_topo();
	return 0;
}