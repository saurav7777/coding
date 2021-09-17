#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;


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
		int n;
		cin>>n;
		vector<int>c(n,0),l(n,0);
		for(int i=0;i<n;i++) cin>>c[i];
		for(int i=0;i<n;i++) cin>>l[i];

		int i=1,minsofar=c[0],curr=c[0];
		int ans=minsofar*l[0];
		while(i<n){
			curr=c[i];
			if(curr<minsofar){
				minsofar=curr;
				ans=ans+ l[i]*minsofar;
			}else{
				ans+= minsofar*l[i];
			}
			i++;
		}
		cout<<ans<<"\n";
	}
}