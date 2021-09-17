#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

class Graph{
	int V;
	list<int>*l;
public:
	Graph(int V){
		this->V=V;
		l=new list<int>[V];
	}

	void addEdge(int x,int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void printGraph(){
		for(int i=0;i<V;i++){
			cout<<"vertex:"<<i<<"->";
			for(int x:l[i]){
				cout<<x<<"->";
			}
			cout<<"\n";
		}
	}
};

class WeightedGraph{
	int V;
	// unordered_map<string,list<pair<string,int>>>l;
	map<string,list<pair<string,int>>>l;

public:
	WeightedGraph(int V){
		this->V=V;
	}

	void addEdge(string x,string y,bool dir,int w){
		l[x].push_back({y,w});
		if(dir){
			l[y].push_back({x,w});
		}
	}

	void printGraph(){
		for(auto p: l){
			string city=p.first;
			list<pair<string,int>> nbrs=p.second;
			cout<<"vertex:"<<city<<"->";
			for(auto nbr:nbrs){
				string dest=nbr.first;
				int wgt=nbr.second;
				cout<<dest<<","<<wgt<<"->";
			}
			cout<<"\n";
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
	int n;
	cin>>n;
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(2,3);
	g.addEdge(1,2);
	g.printGraph();

	WeightedGraph wg(4);
	wg.addEdge("A","B",true,20);
	wg.addEdge("B","D",true,40);
	wg.addEdge("A","C",true,10);
	wg.addEdge("C","D",true,40);
	wg.addEdge("A","D",false,50);
	wg.printGraph();
	return 0;
}