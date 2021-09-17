#include<bits/stdc++.h>
using namespace std;

#define INF 100000
typedef long long int ll;

template<typename T>

class Graph{
public:
	vector<int> *gr;
	int v;
	bool *vis;
	int * tin;
	int * tout;
	int timer=1;
public:
	Graph(int v){
		this->v=v;
		gr= new vector<int>[v];
		vis=new bool[v];
		tin = new int[v]{0};
		tout = new int[v]{0};
		for(int i=0;i<v;i++) vis[i]=false;
	}
	
	void addEgde(int x,int y){
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	void euler_tour_1(int curr){
		cout<<curr<<" ";
		tin[curr]=timer++;
		vis[curr]=true;
		for(auto nbr:gr[curr]){
			if(!vis[nbr]){
				euler_tour_1(nbr);
				cout<<curr<<" ";
				tout[curr]=timer++;
			}
		}
		vis[curr]=false;
		return ;
	}
	
	void euler_tour_2(int curr){
		cout<<curr<<" ";
		tin[curr]=timer++;
		vis[curr]=true;
		for(auto nbr:gr[curr]){
			if(!vis[nbr]){
				euler_tour_2(nbr);
			}
		}
		tout[curr]=timer++;
		cout<<curr<<" ";
		return ;
	}

	void euler_tour_3(int curr){
		cout<<curr<<" ";
		tin[curr]=++timer;
		vis[curr]=true;
		for(auto nbr:gr[curr]){
			if(!vis[nbr]){
				euler_tour_3(nbr);
			}
		}
		tout[curr]=timer;
		cout<<curr<<" ";
		return ;
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

	Graph<int> g(10);
	g.addEgde(1,2);
	g.addEgde(1,3);
	g.addEgde(2,5);
	g.addEgde(2,4);
	g.addEgde(2,6);
	g.addEgde(3,7);
	g.addEgde(7,8);
	g.addEgde(7,9);

	g.euler_tour_1(1);
	cout<<"\n";
	for(int i=1;i<10;i++){
		cout<<i<<"-->"<<g.tin[i]<<" "<<g.tout[i]<<"\n";
	}
	cout<<"\n";
	g.timer=1;
	g.euler_tour_2(1);
	cout<<"\n";
	for(int i=1;i<10;i++){
		cout<<i<<"-->"<<g.tin[i]<<" "<<g.tout[i]<<"\n";
	}
	return 0;
}