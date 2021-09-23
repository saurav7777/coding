#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;

bitset<1000005>b;
vector<ll> primes;
map<ll,ll>mp;

void sieve(){
    b.set();
    b[0]=b[1]=0;
    b[2]=1;
    for(ll i=2;i<=1000001;i++){
        if(b[i]){
            primes.push_back(i);
            for(ll j=i*i;j<=1000001;j=j+i){
                b[j]=0;
            }
        }
    }

    for(int i=0;i<primes.size();i++){
        ll temp=primes[i]*primes[i];
        mp[temp]++;
    }
}

// void calculateprimeflag(){
//     primeflag[0] = primeflag[1] = 1;
//     for(i=2;iflag[i]==0){
//             for(j=i*i;j<LIMIT;j+=i){
//                 primeflag[j] = 1;
//             }
//         }
//     }
// int checkperfectsquare(long long n){
//     double sqrtn = sqrt(n);
//     if(sqrtn == int(sqrtn)){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
    sieve();
   int n;
   cin>>n;
   while(n--){
    ll num;
    cin>>num;
    if(mp.find(num)!=mp.end()){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
   }
    return 0;
}