#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int li;
int mod = 1000000007;
int ans=0,queens=0;
int n=8;
bool vis[100][100]={false};
bool col[8]={false};
bool diag1[8*2 -1]={false};
bool diag2[8*2 -1]={false};

vector<vector<char>> mat(10,vector<char>(10,0));

bool check(int r,int c){

    for(int i=0;i<r;i++){
        if(vis[i][c]) return false;
    }
    
    for(int i=r,j=c;i>=0&&j>=0;i--,j--){
        if(vis[i][j]) return false;
    }

    for(int i=r,j=c;i>=0&&j<n;i--,j++){
        if(vis[i][j]) return false;
    }
    return true;
}

void solve(int r){
     if(r>=n){
        ans++;
        return;
     } 

     for(int i=0;i<n;i++){
        if(mat[r][i]=='*' ||col[i] || diag1[i+r] || diag2[n-1+i-r]) continue;

        col[i]=diag1[i+r]=diag2[n-1+i-r]=1;
        solve(r+1);
        col[i]=diag1[i+r]=diag2[n-1+i-r]=0;

        // if(mat[r][i]!='*' && check(r,i)){
        //     vis[r][i]=true;
        //     solve(r+1);
        //     vis[r][i]=false;
        // }
     }
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input1.txt","r",stdin);
	freopen("output1.txt","w",stdout);
#endif
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
            //cout<<mat[i][j];
        }
    }
    solve(0);
    cout<<ans<<"\n";
    return 0;
}