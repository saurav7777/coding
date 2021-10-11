/*
Shekhar is a bomb defusal specialist. He once encountered a bomb that can be defused only by a secret code. He is given a number N and a number K. And he is also given permutation of first N natural numbers . The defusal code is the largest permutation possible by doing atmost K swaps among a pair of the given permutation. Help him to find the final permutation.
*/

#include<bits/stdc++.h>
#include<algorithm>
#include<cstring>
using namespace std;


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

	int n,k;
	cin>>n>>k;
	vector<pair<int,int>>v;
	int num;
	vector<int>ans;
	map<int,int>pos;
	for(int i=0;i<n;i++){
		cin>>num;
		pos[num]=i;
		ans.push_back(num);
		v.push_back({num,i});
	}	

	sort(v.begin(),v.end(),compare);

	// for(auto x:v){
	// 	cout<<x.first<<" "<<x.second<<"\n";
	// }

	for(int i=0;i<n;i++){
		if(ans[i]<v[i].first && k){
			//cout<<ans[i]<<" "<<v[i].first<<"\n";
			int t=pos[v[i].first];
			pos[ans[i]]=t;
			pos[v[i].first]=i;

			swap(ans[i],ans[t]);
			//cout<<i<<" "<<t<<"\n";
			
			k--;
		}
	}

	for(auto x:ans){
		cout<<x<<" ";
	}
}