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

vector<ll>arr;

ll solve(ll n,ll k){
    int l=0,r=0;
    ll ans=0;
    ll count=0;
    map<ll,ll>mp;
    while(r<n){
        if(mp.find(arr[r])==mp.end()){
            count++;
        }
        mp[arr[r]]++;
        while(count>k){
            ll num=arr[l];
            mp[num]--;
            if(mp[num]==0){
                mp.erase(num);
                count--;
            }
            l++;
        }

        ans+= r-l+1;
        r++;
    }
    return ans;
}

int main() {
    // init_code();
    ll n,k;
    cin>>n>>k;
    fr(0,n){
        ll num;
        cin>>num;
        arr.push_back(num);
    }
    cout<<solve(n,k);
    return 0;
}