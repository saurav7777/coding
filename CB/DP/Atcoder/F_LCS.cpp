#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int dp[3001][3001];

string s,p,ans="";

// string getlcs(int len){
// 	string l;
// 	int i=0,j=0;
// 	while(len > 0){
// 		if(s[i] == p[j]){
// 			// cout<<i<<"-->"<<s[i]<<"\n";
// 			l.push_back(s[i]);
// 			i++;
// 			j++;
// 			len--;
// 		}else{
// 			if(dp[i][j+1]>dp[i+1][j]) {
// 				j++;
// 			}
// 			else i++;
// 		}
// 	}
// 	return l;
// }

// int lcs1(int i,int j){
// 	if(i>=s.length() || j>=p.length()) return 0;
// 	if(dp[i][j]){
// 		return dp[i][j];
// 	}
// 	if(s[i]==p[j])
// 		return (dp[i][j]=1+ lcs1(i+1,j+1));
// 	else 
// 		return (dp[i][j]=max(lcs1(i,j+1),lcs1(i+1,j)));
// }

// string solve(){
// 	int len=lcs1(0,0);
// 	// cout<<len<<"\n";
// 	return getlcs(len);
// }



int lcs(){
	int ns=s.length();
	int np=p.length();

	for(int i=1;i<=ns;i++){
		for(int j=1;j<=np;j++){
			if(s[i-1]==p[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
			}else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}

	// for(int i=1;i<=ns;i++){
	// 	for(int j=1;j<=np;j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }


	int i=ns,j=np,len=dp[ns][np];
	while(len>0){
		if(s[i-1]==p[j-1]){
			ans=s[i-1]+ans;
			i--;
			j--;
			len--;
		}else{
			if(dp[i-1][j]>=dp[i][j-1]){
				i--;
			}else j--;
		}
	}

	
	return dp[ns][np];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../../input.txt","r",stdin);
	freopen("../../output.txt","w",stdout);
#endif
	
	
	cin>>s>>p;

	lcs();
	cout<<ans<<"\n";
	// cout<<solve();
}









