#include<bits/stdc++.h>
using namespace std;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
// #ifndef ONLINE_JUDGE
// 	freopen("input1.txt","r",stdin);
// 	freopen("output1.txt","w",stdout);
// #endif
	string s;
	cin>>s;
	int i=0,j=1,count=1,ans=1;
	int arr[27];
	memset(arr,0,sizeof(arr));
	int n=s.length();
	char ch;
	if(n>0){
		ch=s[0];
	}
	
	// cout<<n<<"\n";
	while(j<n){
		if(s[j]==ch){
			count++;
			ans=max(ans,count);
			ch=s[j];
		}else{
			count=1;
			ch=s[j];
		}
		j++;
	}
	if(n==0) cout<<"0\n";
	else
		cout<<ans<<"\n";
	
}