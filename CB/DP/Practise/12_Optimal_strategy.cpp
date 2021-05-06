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
 
ll dp[1001][1001],num[1001];


ll game_TD(int i,int j,int turn){
	if(i>j) return 0;

	if(dp[i][j]) return dp[i][j];
	ll op1,op2;

	op1 = num[i] + min(game_TD(i+2,j,!turn),game_TD(i+1,j-1,!turn));
	op2 = num[j] + min(game_TD(i,j-2,!turn),game_TD(i+1,j-1,!turn));
	dp[i][j]=max(op1,op2);
	return max(op1,op2);

}

ll game_BU(int n){
	for(int l=0;l<n;l++){
		int i=0,j=l;
		while(j<n){
			// Here x is value of F(i+2, j),
            // y is F(i+1, j-1) and
            // z is F(i, j-2) in above recursive
            // formula
			ll x=(i+2 <= j)?dp[i+2][j]:0;

			ll y = (i+1 <= j-1)?dp[i+1][j-1]:0;

			ll z = (i<= j-2)?dp[i][j-1]:0;

			dp[i][j]=max(num[i] + min(x,y) , num[j] + min(y,z));
			i++,j++;
		}
	}
	return dp[0][n-1];
}

int main() {
	init_code();
    
    int n;
    cin>>n;
    ll sum=0;
    fr(0,n) {
    	cin>>num[i];
    	sum+=num[i];
    }
    // ll ans=game_TD(0,n-1,0);
    ll ans=game_BU(n);
    cout<<ans<<" "<<ans - (sum-ans)<<"\n";
    // cout<<friends_BU(n);
    return 0;
}