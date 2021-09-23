#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod =1000000007;
vector<ll>primes;

bitset<1000006>b;
map<ll,ll>mp;
void sieve(){
    b.set();
    b[0]=b[1]=0;
    b[2]=1;
    for(ll i=2;i<=1000005;i++){
        if(b[i]){
            primes.push_back(i);
            for(ll j=i*i;j<=1000005;j+=i){
                b[j]=0;
            }
        }
    }
}

void solve(ll n){
    for(ll i=2;i*i<=n;i++){
        if(n%i == 0){
            ll cnt=0;
            while(n%i == 0){
                cnt++;
                n/=i;
            }
            mp[i]+=cnt%mod;
        }
    }
    if(n>1){
        mp[n]+=1ll;
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
// #ifndef ONLINE_JUDGE
//  freopen("../input.txt","r",stdin);
//  freopen("../output.txt","w",stdout);
// #endif
    sieve();
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll ans=1,temp=1;
        for(ll i=0;i<n;i++){
            ll num=1;
            cin>>num;
            //temp=temp*num;
            solve(num);
        }
        for(auto it:mp){
            ans=(ans%mod *(it.second +1)%mod)%mod;
        }
        mp.clear();
        cout<<ans%mod<<"\n";
    }
    return 0;
}