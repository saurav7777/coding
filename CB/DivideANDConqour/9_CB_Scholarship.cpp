/*
The coding blocks members went to the success party of their first ever online boot-camp at Murthal. They ordered P number of paranthas. The stall has L cooks and each cook has a rank R. A cook with a rank R can cook 1 parantha in the first R minutes 1 more parantha in the next 2R minutes, 1 more parantha in 3R minutes and so on(he can only cook a complete parantha) ( For example if a cook is ranked 2.. he will cook one parantha in 2 minutes one more parantha in the next 4 mins and one more in the next 6 minutes hence in total 12 minutes he cooks 3 paranthas. In 13 minutes also he can cook only 3 paranthas as he does not have enough time for the 4th parantha). Calculate the minimum time needed to cook all the paranthas.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;

bool check(ll mid,ll n,ll m,ll x,ll y){
    ll total=m+(n-mid)*y;
   // cout<<total<<" "<<mid<<"\n";
    return (total)>= mid*x;
}

ll solve(ll n,ll m,ll x,ll y){
    ll l=1,r=n,mid=0,ans=0;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid,n,m,x,y)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return mid;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
#endif

    ll n,m,x,y;
    cin>>n>>m>>x>>y;
    ll ans=solve(n,m,x,y);
    cout<<ans<<"\n";
    return 0;
}