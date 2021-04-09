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
 
int main() {
	// init_code();
	int n,a,b;
	cin>>n>>a>>b;
	ll arr[n],pre[n];
	fr(0,n) {
		cin>>arr[i];
		pre[i]=0;
	}

	pre[0]=arr[0];
	fr(1,n) pre[i]=arr[i] + pre[i-1];
	int i=0,j=0;
	multiset<ll> s1;


	s1.insert(0);
    ll ans = LONG_MIN;
 
    // ans = (ll)max((ll)ans, pre[a - 1]);

    if(ans<pre[a - 1]) ans=pre[a-1];

    int flag=0;
    for(int i=a;i<n;i++){

    	if (i - b >= 0) {
            if (flag == 0) {
 
                auto it = s1.find(0);
                s1.erase(it);
                flag = 1;
            }
        }

    	if((i-a)>=0){
    		s1.insert(pre[i-a]);
    	}

    	// ans=(ll)max(ans,pre[i]- *s1.begin());

    	if(ans< (pre[i]- *s1.begin())) ans=pre[i]- *s1.begin();


    	if((i-b)>=0){
    		auto it = s1.find(pre[i - b]);
            s1.erase(it);
    	}
    	 // cout<<ans<<"\n";
    }
    cout<<ans;

	return 0;
}