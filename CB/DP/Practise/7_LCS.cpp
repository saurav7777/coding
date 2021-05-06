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
string a,b;

ll LCS_TD(ll n,int i,int m,int j){
	if(i>=n || j>=m) return 0;
	if(dp[i][j]) return dp[i][j];

	ll op1=0,op2=0;
	if(a[i]==b[i]){
		op1=1+ (LCS_TD(n,i+1,m,j+1));
	}else{
		op2=max(LCS_TD(n,i,m,j+1),LCS_TD(n,i+1,m,j));
	}
	dp[i][j]=max(op1,op2);
	return dp[i][j];
}

ll LCS_BU(int n,int m){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[n][m];
}

int main() {
	init_code();
    
    cin>>a>>b;
    int n=a.length();
    int m=b.length();
   

    // cout<<LCS_TD(n,0,m,0)<<"\n";
    cout<<LCS_BU(n,m);
    return 0;
}