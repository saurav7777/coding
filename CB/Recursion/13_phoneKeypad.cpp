#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;

char key[][10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void solve(char *ans,char *s,int i,int j){
    if(s[i]=='\0') {
        ans[j]='\0';
        cout<<ans<<"\n";
        return;
    }
    int dig=s[i]-'0';
    for(int k=0;key[dig][k]!='\0';k++){
        ans[j]=key[dig][k];
        solve(ans,s,i+1,j+1);
    }
   
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
    //char in[]={'2','3','4','\0'};
    char in[]="23";
    char out[100];
    solve(out,in,0,0);
    return 0;
}