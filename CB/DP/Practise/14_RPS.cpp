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
 
ll dp[101][101];
ll colr[101][101];
ll color[101];

ll sum(int s,int e){
	ll ans=0;
	for(int i=s;i<=e;i++){
		ans+=color[i];
		ans=ans%100;
	}
	return ans;
}

ll mixture_TD(int i,int j){
	if(i>=j) return 0;
	if(dp[i][j]) return dp[i][j];

	dp[i][j]=INT_MAX;
	for(int k=i;k<j;k++){
		dp[i][j]=min(dp[i][j],mixture_TD(i,k) + mixture_TD(k+1,j) + sum(i,k)*sum(k+1,j));
	}
	return dp[i][j];
}

ll mixture_BU(int n){
	for(int i=0;i<n;i++){
		colr[i][i]=color[i];
	}

	for(int l=1;l<n;l++){
		int i=0,j=l;

		while(j<n){
			ll val=INT_MAX;
			ll c=0;
			for(int k=i;k<j;k++){
				ll temp = (dp[i][k]+dp[k+1][j] + colr[i][k]*colr[k+1][j]);
				if(temp<val){
					val=temp;
					c= (colr[i][k]+colr[k+1][j])%100;
				}
			}
			dp[i][j]=val;
			colr[i][j]=c;
			i++,j++;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<colr[i][j]<<" ";
		}
		cout<<"\n";
	}
	return dp[0][n-1];
}

int main() {
	init_code();
    
    int n;
    cin>>n;
    fr(0,n) cin>>color[i];
    cout<<mixture_TD(0,n-1)<<"\n";
    // cout<<mixture_BU(n);
    return 0;
}