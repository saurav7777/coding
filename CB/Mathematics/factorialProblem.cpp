#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll calc(ll num,ll mul){
    ll ans=0,base=mul;
    while(mul<=num){
        ans+=(num/mul);
        mul=mul*base;
    }
    return ans;
}

void solve(ll n,ll k){
    map<int,int>prime;
    ll temp=k;
    int i=2;
    while(i<sqrt(temp)){
        while(temp%i==0){
            prime[i]++;
            temp/=i;
        }
        i++;
    }
    if(temp>=2){
        prime[temp]++;
    }
    ll ans=INT_MAX;
    for(auto it=prime.begin();it!=prime.end();it++){
        ans=min(ans,(calc(n,it->first)/it->second));
    }
    cout<<ans<<"\n";

}

int main() {
ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
#endif
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        solve(n,k);
    }
    return 0;
}