#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
using namespace std;
 
void init_code(){
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif 
}
 
ll dp[1000][1000];
ll mat[1001];


ll MCM_TD(ll n,int i,int m,int j){
	
	return dp[i][j];
}

ll MCM_BU(int n){
	for(int i=1;i<=n;i++){
		int x=0,y=i;
		while(y<n){
			ll val=INT_MAX;
			for(int k=x;k<y;k++){
				val=min(val,(dp[x][k]+dp[k+1][y] + mat[x]*mat[k+1]*mat[y+1]));
			}
			dp[x][y]=val;
			x++,y++;
		}
	}
	return dp[0][n-1];
}

int main() {
	init_code();
    
    int n;
    cin>>n;

    fr(0,n+1) cin>>mat[i];

    // cout<<LCS_TD(n,0,m,0)<<"\n";
    cout<<MCM_BU(n);
    return 0;
}