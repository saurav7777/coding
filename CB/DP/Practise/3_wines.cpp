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
 
ll dp[1000][1000],wines[1000];

ll wines_TD(int i,int j,ll n,int year){
	if(i>j) return 0;
	if(i==j) return wines[j]*year;
	if(dp[i][j]) return dp[i][j];
	ll op1,op2;
	op1=wines[i]*year + wines_TD(i+1,j,n,year+1);
	op2=wines[j]*year + wines_TD(i,j-1,n,year+1);
	return max(op1,op2);
}

ll wines_BU(ll n){
	for(int k=1;k<=n;k++){
		int i=1,j=k;
		while(i<=(n-k+1)){
			if(i==j) dp[i][j]=wines[i-1]*n;
			else{
				dp[i][j]=max(wines[i-1]*(n-k+1) +dp[i+1][j] , wines[j-1]*(n-k+1) +dp[i][j-1]);
			}
			// cout<<i<<" "<<j<<" | ";
			cout<<dp[i][j]<<" ";
			i++;
			j++;

			
		}
		cout<<"\n";

	}

	return dp[1][n];
}
int main() {
	init_code();
    int n;
    cin>>n;
    fr(0,n) cin>>wines[i];
    cout<<wines_TD(0,n-1,n,1)<<"\n";
    cout<<wines_BU(n);
    return 0;
}