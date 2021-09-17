#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

class Graph{
	map<int,list<int>>l;
public:
	void addEdge(int x,int y){
		l[x].push_back(y);
		// l[y].push_back(x);
	}

	int bfs(int src,int dest){
		queue<int>q;
		int dist[101];
		int par[101]={0};
		par[src]=src;
		for(int i=0;i<101;i++) dist[i]=INT_MAX;
		q.push(src);
		dist[src]=0;
		while(!q.empty()){
			int node=q.front();
			q.pop();
			for(auto x:l[node]){
				if(dist[x]==INT_MAX){
					q.push(x);
					dist[x]=dist[node]+1;
					par[x]=node;
				}
			}
		}
		// for(int i=0;i<=36;i++){
		// 	cout<<"0 to "<<i<<" = "<<dist[i]<<"\n";
		// }
		// int temp=dest;
		// while(temp!=src){
		// 	cout<<temp<<"-->";
		// 	temp=par[temp];

		// }
		// cout<<src<<"\n";
		return dist[dest];
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
	
	// int board[1000]={0};

	int t;
	cin>>t;
	while(t--){
		Graph g;
		int n;
		cin>>n;
		int board[1000]={0};
		while(n--){
			int s,e;
			cin>>s>>e;
			int diff=(e-s);
			board[s]=diff;
			// cout<<diff<<" ";
		}
		int m;
		cin>>m;
		while(m--){
			int s,e;
			cin>>s>>e;
			int diff=(e-s);
			board[s]=diff;
			// cout<<diff<<" ";
		}

	// board[2]=13;
	// board[5]=2;
	// board[9]=18;
	// board[18]=11;
	// board[17]=-13;
	// board[20]=-14;
	// board[24]=-8;
	// board[25]=10;
	// board[32]=-2;
	// board[34]=-22;
	
		//add Egdes
		int size=100;
		for(int i=0;i<=size;i++){
			for(int dice=1;dice<=6;dice++){
				int j=i+dice;
				j+=board[j];
				if(j<=size){
					g.addEdge(i,j);
				}
			}
		}
		g.addEdge(size,size);
		cout<<g.bfs(0,size)<<"\n";
	}
	return 0;
}