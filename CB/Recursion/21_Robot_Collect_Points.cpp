/*
A robot is moving in two dimensional grid. The width of the grid has a fixed value of 5 while the height of the grid will be given. Robot starts to move from the middle of the width and just below the grid. It can move only in three directions.

1.) Left Upward

2.) Upward

3.) Right Upward

Imgur

Each cell of the grid is filled with a number (-1 or 0 or 1). When the Robot traverse from that cell, he will collect that number and sum up. The Robot has some power to make the value of all the cell of first 5 ∗ 5 subgrids from -1 to 0. He can use that power only once. Can you help the Robot to get the maximum score?
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;
int grid[20][10];
int ans=0;
int cnt=0;
int solve(int i,int j,int h,bool power,int pwrlevel){
    cnt++;
    if(i<0 || j<0 || j==5 ) return 0;

    int t1=0,t2=0,t3=0;
    //use power ,first check power is there or not
    if(power){
        int temp=grid[i][j];
        if(temp == -1 ) temp=0;
        //move upward
        int op1=solve(i-1,j,h,false,4);
        //move upward left
        int op2=solve(i-1,j-1,h,false,4);
        //move upward right
        int op3=solve(i-1,j+1,h,false,4);
        t1=temp+max(op1,max(op2,op3));
    }

    //power already used
    if(!power && pwrlevel>0){
        int temp=grid[i][j];
        if(temp == -1 ) temp=0;
        int op1=solve(i-1,j,h,false,pwrlevel-1);
        //move upward left
        int op2=solve(i-1,j-1,h,false,pwrlevel-1);
        //move upward right
        int op3=solve(i-1,j+1,h,false,pwrlevel-1);

        t2=temp+max(op1,max(op2,op3));
    }

    //do not use power
    if(power)
        t3=grid[i][j]+ max(solve(i-1,j,h,true,0),
                       max(solve(i-1,j-1,h,true,0),
                       solve(i-1,j+1,h,true,0)));
    else if(power==false && pwrlevel<=0){
        t3=grid[i][j] + max(solve(i-1,j,h,false,0),
                       max(solve(i-1,j-1,h,false,0),
                       solve(i-1,j+1,h,false,0)));
    }
    // cout<<ans<<" ";
    ans=max(t1,max(t2,t3));
    return ans;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
    int t;
    cin>>t;
    while(t--){
        int h;
        cin>>h;
        // cout<<h<<"\n";
        for(int i=0;i<h;i++){
            for(int j=0;j<5;j++){
                cin>>grid[i][j];
            }
        }
        int res=INT_MIN;
        res=max(res,solve(h-1,1,h,true,0));
        // cout<<res<<" ";
        res=max(res,solve(h-1,2,h,true,0));
        // cout<<res<<" ";
        res=max(res,solve(h-1,3,h,true,0));
       
        cout<<res<<"\n";
    }

    return 0;
}