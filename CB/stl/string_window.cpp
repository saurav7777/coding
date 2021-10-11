#include<bits/stdc++.h>
#include<algorithm>
#include<cstring>
using namespace std;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif

	string s,t;
	getline(cin,s);
	getline(cin,t);
	int n=s.length(),m=t.length();
	// cout<<m<<" "<<n;
	int l=0,r=0,resl=-1,resr=n+m;
	map<char,int>ms,mt;
	for(auto x:t) mt[x]++;

	for(r=0;r<n;r++){
		ms[s[r]]++;
		bool good=true;

		for(auto p:mt){
			if(ms.count(p.first)==0 || (ms[p.first]< p.second)){
				good=false;
				break;
			}
		}

		if(!good) continue;

		//if it is a good window
		while(l<n && l<=r && ((mt.count(s[l])==0) || ms[s[l]]>mt[s[l]] )){
			if(ms.count(s[l])==0) ms.erase(s[l]);
			else ms[s[l]]--;
			l++;
		}

		// cout<<l<<" "<<r<<"\n";

		if((resr-resl+1)>(r-l+1)){
			resl=l;
			resr=r;
		}
	}	
	// cout<<resr<<" "<<resl<<"\n";
	if(resl == -1) cout<<"No String\n";
	else cout<<s.substr(resl,resr-resl+1)<<"\n";

}