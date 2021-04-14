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
    // fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif 
}
 
int main() {
	 fast_io;
    init_code();

   	int n,sum;
   	cin>>n>>sum;
   	map<ll, int> prevSum;
   	// vector<ll>arr(n,0);
   	// for(int i=0;i<n;i++){
   	// 	cin>>arr[i];
   	// }
  
   	ll res = 0;
 
    // Sum of elements so far.
    ll currsum = 0;
 	prevSum[0]=1;
    for (int i = 0; i < n; i++) {
 		ll num;
 		cin>>num;
        currsum += num;
 
        // if (currsum == sum)
        //     res++;

        if (prevSum.find(currsum - sum) != prevSum.end())
            res += (prevSum[currsum - sum]);
 
        prevSum[currsum]++;
    }
 	
 	cout<<res;
    return 0;
}