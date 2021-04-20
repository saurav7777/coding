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

ll minsteps_TD(ll n){
	if(n==1) return 0;
	if(n<=0) return 0;

	if(dp[n]) return dp[n];
	ll op1,op2,op3;
	op1=op2=op3= INT_MAX;
	if(n%3 ==0){
		op1=1 + minsteps_TD(n/3);
	}

	if(n%2 ==0){
		op2=1 + minsteps_TD(n/2);
	}

	op3 = 1 + minsteps_TD(n-1);

	dp[n]=min(op1,min(op2,op3));
	return dp[n];
}

ll minsteps_BU(ll n){
	dp[1]=0;
	ll op1,op2,op3;
	for(int i=2;i<=n;i++){
		op1=op2=op3= INT_MAX;
		if(i%3 ==0){
			
			op1 = 1+dp[i/3];
		}

		if(n%2 ==0){
			op2=1 + dp[i/2];
		}

		op3 = 1 + dp[i-1];

		dp[i]=min(op1,min(op2,op3));
	}
	return dp[n];
}
int main() {
	init_code();
    cout<<minsteps_TD(5)<<"\n";
    cout<<minsteps_BU(5);
    return 0;
}