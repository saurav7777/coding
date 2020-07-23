#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
// #ifndef ONLINE_JUDGE
// 	freopen("input1.txt","r",stdin);
// 	freopen("output1.txt","w",stdout);
// #endif
	int n;
	cin>>n;
	ll prev=0,ans=0;
	for(int i=0;i<n;i++){
		ll num;
		cin>>num;

		prev=max(prev,num);
		if(i==0) continue;
		ans+=abs(prev-num);

	}
	cout<<ans<<"\n";
}