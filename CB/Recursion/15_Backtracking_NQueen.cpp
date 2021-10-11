#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;
bitset<30>col,d1,d2;
int c=0;

bool check_NQueen_bitset(int grid[][10],int i,int n){
    if(i==n){
        for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){
                cout<<grid[x][y]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
        c++;
        return true;
    }
    for(int j=0;j<n;j++){
        if(!col[j] && !d1[i+j] && !d2[i-j+n-1]){
            col[j]=d1[i+j]=d2[i-j+n-1]=1;
            grid[i][j]=1;
            check_NQueen_bitset(grid,i+1,n);
            grid[i][j]=0;
            col[j]=d1[i+j]=d2[i-j+n-1]=0;
        }
    }
    return false;
}


bool check(int grid[][10],int i,int j,int n){
    // check for column
    for(int row=0;row<i;row++){
        if(grid[row][j]==1) return false;
    }
    // check for left diagonal
    int x=i,y=j;
    while(x>=0 && y>=0){
        if(grid[x][y]==1) return false;
        x--;
        y--;
    }
    //check for right diagonal
    x=i,y=j;
    while(x>=0 && y<n){
        if(grid[x][y]==1) return false;
        x--;
        y++;
    }
    return true;
}

bool check_NQueen(int grid[][10],int i,int n){
    if(i == n){
        // for(int x=0;x<n;x++){
        //     for(int y=0;y<n;y++){
        //         cout<<grid[x][y]<<" ";
        //     }
        //     cout<<"\n";
        // }
        //cout<<"\n";
        c++;
        return true;
    }    

    for(int j=0;j<n;j++){
        if(check(grid,i,j,n)){
            grid[i][j]=1;
            check_NQueen(grid,i+1,n);
            //if(check_NQueen(grid,i+1,n)) return true;
            grid[i][j]=0;
        }
    }
    return false;

}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
    int n=4;
    //cout<<n<<"\n";
    int grid[10][10]={0};
    //bool ans=check_NQueen(grid,0,n);

    bool ans=check_NQueen_bitset(grid,0,n);
    if(ans) cout<<"sol exist\n";
    else cout<<"sol does not exist\n";
    cout<<c<<"\n";
    return 0;
}