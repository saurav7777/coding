#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;

bitset<1000006>b;
vector<ll> primes;

void sieve(int *p){
   
    for(int i=0;i<100005;i++){
        p[i]=1;
    }
    p[0]=0;
    p[1]=0;
    for(int i=2;i*i<=100005;i++){
        if(p[i]==1){
            for(int j=2*i;j<100005;j+=i){
                p[j]=0;
            }
        }
    }

}

void bitset_sieve(){
    b.set();
    b[0]=b[1]=0;
    b[2]=1;
    for(ll i=2;i<=100005;i++){
        if(b[i]){
            primes.push_back(i);
            for(ll j=i*i;j<=100005;j=j+i){
                b[j]=0;
            }
        }
    }
}

void segmented_sieve(ll m,ll n){
    ll sqr=(ll)sqrt(n);
    vector<ll>p;
    vector<ll>bi(sqr+1,1);
    bi[0]=bi[1]=0;
    bi[2]=1;
    for(ll i=2;i<=sqr;i++){
        if(bi[i]){
            p.push_back(i);
           // cout<<i<<" ";
            for(ll j=i*i;j<=sqr;j=j+i){
                bi[j]=0;
            }
        }
    }

    //bool seg[n-m+1];
    int s=(n-m+1);
    //cout<<s<<"\n";
    vector<int> seg(n-m+1,0);
    for(int i=0;i<n-m+1;i++){
        seg[i]=0;
    }
    for(ll x:p){
        //cout<<x<<" ";
        if(x*x > n){
            break;
        }
        int start=(m/x)*x;
        if(x>=m && x<=n){
            start=2*x;
        }

        if(start<m){
            start+=x;
        }
        for(int i=start;i<=n;i=i+x){
            seg[i-m]=1;
            //cout<<(i-m)<<" ";
        }
        //cout<<"\n";
    }
    cout<<"\n";
    for(int i=m;i<=n;i++){
        if(seg[i-m]==0 && i!=1){
            cout<<i<<" ";
        }
    }
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
    // int n;
    // cin >> n;
   // cout<<n;
     // int prime[100005]={1};
     // sieve(prime);
    // int pre[100005]={0};

    // for(int i=0;i<100005;i++){
    //     pre[i]=pre[i-1]+prime[i];
    //     //cout<<pre[i];
    // }
    // while(n--){
    //     int a,b;
    //     //cout<<n;
    //     cin>>a>>b;
    //     cout<<pre[b]-pre[a-1]<<"\n";

    // }

   

   //bitset
    //cout<<n;
    // bitset_sieve();
    // for(int i=0;i<100;i++){
    //     cout<<primes[i]<<" ";
    // }


    //segmented sieve
    segmented_sieve(1000,1500);
    return 0;
}