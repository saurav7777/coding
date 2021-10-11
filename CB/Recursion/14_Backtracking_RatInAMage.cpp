#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;
int grid[1001][1001];
char maze[1001][1001];

bool RatinMaze(char maze[10][10],int sol[][10],int i,int j,int m,int n){
    if(i==m && j==n){
        sol[i][j]=1;

        //print the sol
        for(int x=0;x<=m;x++){
            for(int y=0;y<=n;y++){
                cout<<sol[x][y]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
        return true;
    }
    //Rat should be inside maze
    if(i>m || j>n){
        return false;
    }
    if(maze[i][j]=='X') return false;

    sol[i][j]=1;  //backtrack
    bool right=RatinMaze(maze,sol,i,j+1,m,n);
    bool down=RatinMaze(maze,sol,i+1,j,m,m);
    sol[i][j]=0;
    if(right || down){
        return true;
    }
    return false;
}

bool RightMost_sol(int i,int j,int n,int m){
    if(i==n && j==m){
        grid[i][j]=1;
         //print the sol
        for(int x=0;x<=n;x++){
            for(int y=0;y<=n;y++){
                cout<<grid[x][y]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
        return true;   
    }

    if(i>m || j>n){
        return false;
    }
    if(maze[i][j]=='X') return false;

    grid[i][j]=1;  //backtrack
    bool right=RightMost_sol(i,j+1,n,m);
    if(right) return true;
    bool down=RightMost_sol(i+1,j,n,m);
    if(down) return true;
    grid[i][j]=0;
   
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
    // char maze[10][10]={"0000",
    //                  "00X0",
    //                  "000X",
    //                  "0X00"};
    // int sol[10][10]={0};
    // int m=3,n=3;
    // bool ans=RatinMaze(maze,sol,0,0,m,n);
    // if(ans) cout<<"sol exist\n";
    // else cout<<"sol does not exist\n";

    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maze[i][j];
        }
    }

    if(!RightMost_sol(0,0,n-1,m-1)){
        cout<<"-1\n";
    }

    return 0;
}