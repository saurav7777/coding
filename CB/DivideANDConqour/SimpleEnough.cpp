#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;

ll solve(ll n,ll l,ll r,ll i, ll j){
    if((i<l && j<l) || (i>r && j>r)) return 0;
    if(i>=j && (i>=l && j<=r) ) {
        // if((i>=l && j<=r)) cout<<"1";
        // else cout<<"0";
        return 1;
    }
    ll mid=(i+j)/2;
    ll x1=solve(n/2,l,r,i,mid-1);
    // if(mid>=l && mid<=r) cout<<"1";
    // else cout<<"0";
    ll x2=solve(n/2,l,r,mid+1,j);

    return x1+x2+(((n%2)?1:0)&&(mid>=l && mid<=r));
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
    ll n,l,r;
    cin>>n>>l>>r;
    ll num=pow(2,ceil(log2(n)))-1;
    cout<<solve(n,l-1,r-1,0,num);
    return 0;
}