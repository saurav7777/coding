#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int p =1000000007;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
	long long x;
     cin >> x;

     vector<long long> vec;
     vec.resize(x);

     long long nOfDivisors = 1;

     for (long long i = 0; i<x; i++)
     {
          cin >> vec[i];
          nOfDivisors = (nOfDivisors*(vec[i] + 1)) % p;
     }

     long long ans = 1;


     for (long long i = 0; i<x; i++)
     {
          vec[i] = (nOfDivisors*vec[i])%p;
          vec[i] = (vec[i]*500000004)%p; // 500000004 is mod_inv(2,1000000007);
          ans = (ans*(vec[i] + 1)) % p;
     }

     cout << ans << endl;
     //cin >> x;
     return 0;
	//sieve();
	// ll x;
	// ll ans=1;
	// cin>>x;
	// ll d=x-1;
	// d=d%mod;
	// ll temp=((d*(d+1))/2ll)%mod;
	// //cout<<temp<<"\n";
	// while(x--){
	// 	ll num;
	// 	cin>>num;
	// 	num=num%mod;
	// 	ll temp1=(num*(num+1ll)/2ll)%mod;
	// 	//cout<<temp1<<" ";
	// 	ll sum=((temp*temp1)%mod + temp1%mod)%mod;

	// 	cout<<sum<<" ";
	// 	ans=(ans*((sum)%mod + 1ll))%mod;
	// }
	// cout<<ans%mod<<"\n";
	//return 0;
}