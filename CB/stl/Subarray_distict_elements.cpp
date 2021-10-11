/*
Shekhar is a bomb defusal specialist. He once encountered a bomb that can be defused only by a secret code. He is given a number N and a number K. And he is also given permutation of first N natural numbers . The defusal code is the largest permutation possible by doing atmost K swaps among a pair of the given permutation. Help him to find the final permutation.
*/

#include<bits/stdc++.h>
#include<algorithm>
#include<cstring>
using namespace std;
int mod =1000000007;

bool compare(pair<int,int>a,pair<int,int>b){
	return a.first>b.first;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif

	int n,sum=0;
	cin>>n;
	vector<int>v;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		v.push_back(num);
	}
	int l=0,r=0,ans=0,currsum=0;
	map<int,int>m;
	bool flag=false;
	for(r=0;r<n;r++){
		
		if(m.find(v[r])==m.end() || m[v[r]]==0) {
			//cout<<r-l+1<<" ";
			m[v[r]]++;
			ans=max(ans,r-l+1);
			flag=true;
		}else{
			while(l<=r && l<n && m[v[r]]==1){
				// currsum=currsum-v[l];
				m[v[l]]--;
				l++;
				ans=(r-l+1);
				cout<<ans<<" ";
				sum=(sum%mod +(ans%mod *(ans%mod +1)/2))%mod;
				// int i=ans;
				// int j=1;
				// while(j<=ans){
				// 	//cout<<l*ans<<" ";
				// 	sum=(sum%mod + (i*j)%mod)%mod;
				// 	j++;
				// 	i--;
				// }
			}
			m[v[r]]++;
			flag=false;
		}
	}
	if(flag){
		ans=(r-l+1);
		cout<<ans<<" ";
		sum=(sum%mod +(ans%mod *(ans%mod +1)/2))%mod;
	}
	cout<<sum<<"\n";
}