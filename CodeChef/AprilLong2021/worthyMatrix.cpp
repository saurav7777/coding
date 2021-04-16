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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif 
}
 

vector<vector<ll>>mat;

ll getSum(int y1,int x1,int l){
	if(l==0) return 0;
	int x2=x1+l-1, y2=y1+l-1;
	return (mat[y2][x2] - mat[y2][x1-1] - mat[y1-1][x2] + mat[y1-1][x1-1]);
}

/*
	1.calculate prefix matrix  
*/
int main() {
    // init_code();
    int t;
    cin>>t;
    while(t--){
    	ll n,m,k;
    	cin>>n>>m>>k;
    	mat.clear();
    	mat.resize(n+1,vector<ll>(m+1,0));

    	fr(1,n+1){
    		rep(j,1,m+1){
    			cin>>mat[i][j];
    		}
    	}

    	//prefix sum
		fr(1,n+1){
    		rep(j,1,m+1){
    			mat[i][j]=mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1] + mat[i][j];
    		}
    	}

    	// fr(1,n+1){
    	// 	rep(j,1,m+1){
    	// 		cout<<mat[i][j]<<" ";
    	// 	}
    	// 	cout<<"\n";
    	// }

    	// calculate ans by finding min L for each submatrix whose left corner is x, y
    	ll ans=0;
    	fr(1,n+1){
    		rep(j,1,m+1){

    			int l=0,r=min(n-i+1,m-j+1);
    			int mid=0,t=r;
    			
    			while(l<r){
    				mid=(l+r+1)/2;
    				// cout<<i<<" "<<j<<" "<<mid<<"-->"<<getSum(i,j,mid)<<"\n";
    				if(k > ((getSum(i,j,mid)/ (mid*mid)))){
    					l=mid;
    				}else {
    					r=mid-1;
    				}
    			}
    			// cout<<"l "<<t<<" "<<l<<"\n";
    			ans = ans + (t - l);
    		}
    		// cout<<"\n";
    	}
    	cout<<ans<<"\n";

    }
    return 0;
}