#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;
bitset<30>col,d1,d2;
int ans=0;
int n=3;

bool isSafe(int grid[][10],int x,int y,int n){
    if(x<n && x>=0 && y<n && y>=0 && grid[x][y]==1){
        return true;
    }
    return false;
}

void Knight_tour(int grid[][10],int i,int j,int cnt){
    ans=max(ans,cnt);
    int x[]={ 2, 1, -1, -2, -2, -1, 1, 2 };
    int y[]={ 1, 2, 2, 1, -1, -2, -2, -1 };
    
    //cout<<i<<" "<<j<<" "<<cnt<<"\n";
    // grid[i][j]=0;
    for(int k=0;k<8;k++){
        int dx=i+x[k];
        int dy=j+y[k];
        if(isSafe(grid,dx,dy,n)){
            grid[dx][dy]=0;
            Knight_tour(grid,dx,dy,cnt+1);
            grid[dx][dy]=1;
        }
    }
    // grid[i][j]=1;
    
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
    cin>>n;
    int grid[10][10];
    int cnt1=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
            if(grid[i][j] == 1) cnt1++;
        }
    }
    //grid[0][0]=0;
    Knight_tour(grid,0,0,0);
    // if(ans) cout<<"sol exist\n";
    // else cout<<"sol does not exist\n";
    cout<<(cnt1)-ans<<"\n";
    return 0;
}