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
 
ll dp[1001];


ll friends_TD(int n){
	if(n<0) return 0;
	if(n<=1) return 1 ;

	if(dp[n]) return dp[n];
	
	ll op1= friends_TD(n-1);
	ll op2 = friends_TD(n-2)* (n-1);
	return op1+op2;

}

ll friends_BU(int n){
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1] + dp[i-2]*(i-1);
	}
	return dp[n];
}

int main() {
	init_code();
    
    int n;
    cin>>n;
    
    // cout<<friends_TD(n)<<"\n";
    cout<<friends_BU(n);
    return 0;
}