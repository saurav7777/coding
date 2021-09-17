// Bipartite graph check
// shortest cycle in graph


#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int cnt0=0,cnt1=0,can=1;

class Graph{
	int V;
	list<int>*l;
	int *vis;
	ll mod=998244353;
public:
	Graph(int v){
		this->V=v;
		l=new list<int>[v];
		vis= new int[v+1];
	}

	void addEdge(int x,int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}

	ll powm(ll a,ll b){
		ll ans=1;
		a=a%this->mod;
		while(b){
			if(b&1){
				ans=(ans*a)%mod;
			}
			a=(a*a)%mod;
			b=b>>1;
		}
		return ans%mod;
	}

	void dfs(int i,int parity=0){
		if(vis[i]){
			if( 1 + parity != vis[i]){
				can=0;
			}
			return;
		}
		// cout<<i<<" ";
		if(parity == 0)
			cnt0++,vis[i]=1;
		else
			cnt1++,vis[i]=2;

		for(auto nbr:l[i]){
			dfs(nbr,1-parity);
		}
	}

	ll no_of_beautiful_graph(){
		ll ans=1;
		
		for(int i=0;i<V;i++){
			vis[i]=0;
		}

		for(int i=1;i<V;i++){
			if(!vis[i]){
				cnt1=0,cnt0=0,can=1;
				dfs(i,0);
				if(!can) return 0;

				ans = (ans * (powm(2,cnt0) + powm(2,cnt1)%mod)%mod);
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

	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		Graph gr(n+1);
		while(m--){
			int u,v;
			cin>>u>>v;
			gr.addEdge(u,v);

		}
		cout<<gr.no_of_beautiful_graph()<<"\n";
	}
	return 0;
}