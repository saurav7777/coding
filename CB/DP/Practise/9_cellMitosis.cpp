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
 
ll dp[1000];
ll x,y,z;


ll cell_BU(int n){
	dp[0]=dp[1]=0;
	for(int i=2;i<=n;i++){
		if(n%2){
			//odd
			ll op1= dp[i-1] + y; //inc
			ll op2 = dp[i/2 + 1] + x + z; // double and dec
			dp[i] = min(op1,op2);
		}else{
			// even
			ll op1= dp[i-1] + y;
			ll op2 = dp[i/2] + x;
			dp[i] = min(op1,op2);
		}
	}

	return dp[n];
}

int main() {
	init_code();
    
    int n;
    cin>>n;
    cin>>x>>y>>z;
    // cout<<LCS_TD(n,0,m,0)<<"\n";
    cout<<cell_BU(n);
    return 0;
}