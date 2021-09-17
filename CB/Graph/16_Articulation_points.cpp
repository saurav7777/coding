#include<bits/stdc++.h>
using namespace std;

#define INF 100000
typedef long long int ll;

const int n=100;

vector<int>gr[n];
int disc[n],lwst[n];
int timer=1;
vector<int>art_p;
vector<pair<int,int>>bridge;

void dfs(int curr,int par){
	disc[curr]=lwst[curr]= timer++;
	int no_of_child=0;
	// cout<<curr<<"\n";
	for(auto child:gr[curr]){
		//not visited
		if(disc[child]==0){
			dfs(child,curr);
			no_of_child++;
			lwst[curr]=min(lwst[child],lwst[curr]);

			//articulation point
			if(par!=0 && lwst[child]>= disc[curr]){
				art_p.push_back(curr);
			}

			//bridge
			if(lwst[child] > disc[curr]){
				bridge.push_back({curr,child});
			}

		}else if(child != par){
			//backedge
			lwst[curr]=min(disc[child],lwst[curr]);
		}
	}
	if(par==0 && no_of_child>=2){
		art_p.push_back(curr);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif

	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	// time=1;
	dfs(1,0);
	for(auto x:art_p){
		cout<<x<<"\n";
	}
	for(auto x:bridge){
		cout<<x.first<<"-->"<<x.second<<"\n";
	}
	return 0;
}