#include<bits/stdc++.h>
using namespace std;

#define INF 100000
typedef long long int ll;

template<typename T>

class Graph{
	unordered_map<T,list<pair<T,int>>>l;
	vector<vector<int>>edges;
	int v;
public:

	void addEdge(T x,T y,int cost,bool bidir=true){
		edges.push_back({x,y,cost});
		l[x].push_back({y,cost});
		if(bidir)
			l[y].push_back({x,cost});
	}

	void printGraph(){
		for(auto x:l){
			auto nbrs=x.second;
			auto node=x.first;
			cout<<node<<" --> ";
			for(auto y:nbrs){
				cout<<y.first<<" "<<y.second<<" , ";
			}
			cout<<"\n";
		}
	}

	void floyd_Warshal(vector<vector<int>>g){
		vector<vector<int>>dist(g);
		int v=g.size();
		//phases int Kth phase we include vertices (1,2,3...K) as intermediate
		for(int k=0;k<v;k++){
			//iterarte over 2D matrix
			for(int i=0;i<v;i++){
				for(int j=0;j<v;j++){
					//if the vertex k is included then and can we minimise the dist?
					if(dist[i][j] > dist[i][k]+dist[k][j]){
						dist[i][j] = dist[i][k]+dist[k][j];
					}
				}
			}
		}
		for(int i=0;i<v;i++){
			for(int j=0;j<v;j++){
				cout<<dist[i][j]<<" ";
			}
			cout<<"\n";
		}
	}

	vector<int> bellman_Ford(T src){
		int n=edges.size();
		vector<int>dist(n+1,INT_MAX);
		dist[src]=0;

		//relax all edges
		for(int i=0;i<n-1;i++){
			for(auto egde:edges){
				int u= egde[0];
				int v= egde[1];
				int wt=egde[2];

				if(dist[u]!= INT_MAX && dist[u]+wt < dist[v]){
					dist[v]=dist[u]+wt;
				}
			}
		}

		//negative cycle detection
		for(auto egde:edges){
			int u=egde[0];
			int v=egde[1];
			int wt=egde[2];

			if(dist[u]!= INT_MAX && dist[u]+wt < dist[v]){
				cout<<"negative weight cycle";
				break;
			}
		}
		return dist;
	}

	void dijkstra(T src){
		unordered_map<T,int>dist;
		unordered_map<T,T>parent;
		//set all dist to INFINITY
		for(auto x:l){
			dist[x.first]=INT_MAX;
			parent[x.first]=x.first;
		}

		dist[src]=0;  // set source distance to 0

		// make a set to find out node with min distance
		set<pair<int,T>>s;
		s.insert({0,src});

		while(!s.empty()){
			auto p = *(s.begin());

			T node = p.second;
			int nodeDist=p.first;
			s.erase(s.begin());
			cout<<node<<" --> ";
			for(auto nbrs:l[node]){
				if(dist[nbrs.first] > nodeDist+nbrs.second){
					//int the set update the dist
					//first remove the old pair and then insert
					T dest=nbrs.first;
					auto f=s.find({dist[dest],dest});
					if(f!=s.end()){
						s.erase(f);
					}
					dist[dest]= nodeDist + nbrs.second;
					parent[dest]=node;
					s.insert({dist[dest],dest});
				}
			}
		}

		//print dist to all other nodes
		for(auto x:dist){
			cout<<x.first<<" --> "<<x.second<<"\n";
		}
		cout<<"\n";
		for(auto x:parent){
			cout<<x.first<<" --> "<<x.second<<"\n";
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

	Graph<int> gr;
	gr.addEdge(1,2,3);
	gr.addEdge(2,3,4);
	gr.addEdge(1,3,-10);
	// gr.addEdge(3,4,2);
	// gr.addEdge(1,4,7);
	// gr.dijkstra(1);

	//belman ford
	vector<int>dist=gr.bellman_Ford(1);
	for(int i=1;i<dist.size();i++){
		cout<<"Node:"<<i<<" is at "<<dist[i]<<"\n";
	}

	//floyd Warshal
	// INF to deal with overflow
	vector<vector<int>>g={{0,INF,-2,INF},
						  {4,0,3,INF},
						  {INF,INF,0,2},
						  {INF,-1,INF,0}};
	gr.floyd_Warshal(g);


	// Graph<string> gr;
	// gr.addEdge("amritsar","Delhi",1);
	// gr.addEdge("amritsar","Jaipur",4);
	// gr.addEdge("Jaipur","Delhi",2);
	// gr.addEdge("Jaipur","Mumbai",8);
	// gr.addEdge("Bhopal","Agra",2);
	// gr.addEdge("Mumbai","Bhopal",3);
	// gr.addEdge("Agra","Delhi",1);
	// // gr.addEdge("Delhi","Bhopal",1);
	// // gr.printGraph();
	// gr.dijkstra("amritsar");

	return 0;
}