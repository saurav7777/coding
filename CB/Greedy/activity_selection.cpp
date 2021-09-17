#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int>a,pair<int,int>b){
	return a.second<b.second;
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
		int n,x,y;
		cin>>n;
		int ans=1;
		vector<pair<int,int>>v;
		for(int i=0;i<n;i++){
			cin>>x>>y;
			v.push_back({x,y});
		}
		sort(v.begin(),v.end(),compare);
		int i=1;
		int curr=v[0].second;
		while(i<n){
			if(v[i].first >=curr){
				ans++;
				curr=v[i].second;
			}
			i++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}