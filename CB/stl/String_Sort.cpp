#include<bits/stdc++.h>
using namespace std;

bool compare(string a,string b){
	int s1=a.length(),s2=b.length();
	if(a>=b){
		if(a.find(b)!= string::npos){
			return a>b;
		}
	}else {
		if(b.find(a)!= string::npos){
			return a<b;
		}
	}
	return a<b;
}

int main() {
	int n;
	cin>>n;
	string s[n];
	cin.get();
	for(int i=0;i<n;i++){
		getline(cin,s[i]);
	}
	sort(s,s+n,compare);
	for(int i=0;i<n;i++){
		cout<<s[i]<<"\n";
	}
	return 0;
}