#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
	float p,diff=1.0,deno=365,num=365;
	cin>>p;

	int ans=0;
	bool flag=true;
	while(diff > 1-p){
		diff= diff*(num/deno);
		num--;
		ans++;
		//cout<<ans<<" "<<diff<<"\n";
	}
	cout<<ans<<"\n";
	return 0;
}