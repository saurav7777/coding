#include<bits/stdc++.h>
using namespace std;

#define INF 100000
typedef long long int ll;

int n=4;
int r= (1<<n);
int c=n;

int dp[10000][100];

int dist[10][10]= {
		{0,20,42,25},
		{20,0,30,34},
		{42,30,0,10},
		{25,34,10,0}
};

// mask for all visted cities
int Visited_all= (1<<n)-1;

int tsp(int mask,int pos){
	if(mask== Visited_all){
		return dist[pos][0];
	}

	//lookup
	if(dp[mask][pos] != -1) return dp[mask][pos];

	int ans=INF;
	//try to go to all unvisited cities
	for(int city=0;city<n;city++){
		if((mask & (1<<city))==0){
			int newAns=dist[pos][city] + tsp(mask|(1<<city),city);
			ans=min(ans,newAns);
		}
	}
	return dp[mask][pos]=ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			dp[i][j]=-1;
		}
	}
	cout<<tsp(1,0);
	
	return 0;
}