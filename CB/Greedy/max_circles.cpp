#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool compare(pair<int,int>a,pair<int,int>b){
	return a.first<b.first;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
	ll n,x,y;
	cin>>n;
	int ans=0;
	vector<pair<ll,ll>>v;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		v.push_back({x,y});
	}
	sort(v.begin(),v.end(),compare);
	int i=1;
	int prev=v[0].first+v[0].second;
	int curr=0;
	while(i<n){
		curr = v[i].first-v[i].second;
		if(curr>=prev){
			prev=v[i].first+v[i].second;
		}else{
			ans++;
		}
		i++;
	}
	cout<<ans<<"\n";
	return 0;
}