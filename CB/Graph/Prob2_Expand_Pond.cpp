#include<bits/stdc++.h>
using namespace std;

int mat[1001][1001];
int matid[1001][1001];

map<int,int>size;
int n,m;
int vis[1001][1001];

int xx[]={-1,0,1,0};
int yy[]={0,-1,0,1};

bool check(int x,int y){
	return x>=0 && x<n && y>=0 && y<m && mat[x][y] && !vis[x][y];
}	

int bfs(int i,int j,int id){
	queue<pair<int,int>>q;

	q.push({i,j});
	matid[i][j]=id;
	vis[i][j]=true;
	int s=0;
	while(!q.empty()){
		auto node=q.front();
		q.pop();
		s++;
		int x=node.first;
		int y=node.second;
		for(int k=0;k<4;k++){
			int dx=x+xx[k];
			int dy=y+yy[k];
			if(check(dx,dy)){
				vis[dx][dy]=true;
				matid[dx][dy]=id;
				q.push({dx,dy});
			}
		}
	}
	return s;
}


void solve(){
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			vis[i][j]=false;
			matid[i][j]=false;
		}
	}
	int id=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(mat[i][j] && !vis[i][j]){
				int s=bfs(i,j,id);
				size[id]=s;
				id++;
				// cout<<"s-->"<<s<<"\n";
			}
		}
	}

	int ans=0,temp=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(mat[i][j]==0){
				temp=0;
				set<int>ids;
				for(int k=0;k<4;k++){
					int dx=i+xx[k];
					int dy=j+yy[k];
					if( dx>=0 && dx<n && dy>=0 && dy<m && mat[dx][dy]){
						ids.insert(matid[dx][dy]);
					}
				}	
				for(auto id:ids){
					temp+= size[id];
				}
				ans=max(ans,temp+1);
			}
		}
	}
	cout<<ans<<"\n";
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif

	
	cin>>n>>m;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>mat[i][j];
		}
	}
	solve();

	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		cout<<mat[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }

	// cout<<"\n";
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		cout<<matid[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }

	return 0;
}