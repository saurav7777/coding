#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int lli;
int mod = 1000000007;

int x[]={1,0,-1,0};
int y[]={0,1,0,-1};
int R=7,C=7,n=7;
bool vis[7][7]={false};
int steps=0,ans=0;
string s;
bool check(int dx,int dy){
    return (dx>=0 && dx<R && dy>=0 && dy<R && !vis[dx][dy]);
}

void solve(int r,int c){
    //cout<<"steps:"<<steps<<"\n";

    if((r==R-1 && c==0)){
        if(steps==(R*C -1)){
             ans++;
             //cout<<ans<<"\n";
        }
        return;
    }

    if (((r + 1 == n || (vis[r - 1][c] && vis[r + 1][c])) && c - 1 >= 0 && c + 1 < n && !vis[r][c - 1] && !vis[r][c + 1]) ||
        ((c + 1 == n || (vis[r][c - 1] && vis[r][c + 1])) && r - 1 >= 0 && r + 1 < n && !vis[r - 1][c] && !vis[r + 1][c]) ||
        ((r == 0 || (vis[r + 1][c] && vis[r - 1][c])) && c - 1 >= 0 && c + 1 < n && !vis[r][c - 1] && !vis[r][c + 1]) ||
        ((c == 0 || (vis[r][c + 1] && vis[r][c - 1])) && r - 1 >= 0 && r + 1 < n && !vis[r - 1][c] && !vis[r + 1][c]))
        return;

    vis[r][c]=true;
    //cout<<r<<" "<<c<<"\n";

    for(int j=0;j<4;j++){
        int dx=r+x[j];
        int dy=c+y[j];
        //cout<<dx<<" "<<dy<<"\n";
        if(check(dx,dy)){
            steps++;
            solve(dx,dy);
            steps--;
        }
       
    }
    vis[r][c]=false;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	//freopen("input1.txt","r",stdin);
	freopen("output1.txt","w",stdout);
#endif
   // cin>>s;
    //memset(vis,false,sizeof(vis));
    cout<<"steps"<<"\n";
    solve(0,0);
    
    cout<<ans<<"\n";
}