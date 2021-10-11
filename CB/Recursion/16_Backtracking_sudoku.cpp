#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;
int c=0;


bool canPlace(int mat[][9],int i,int j,int n,int num){
    int x=i,y=j;
    // check for column
    for(x=0;x<n;x++){
        if(mat[x][j]==num) return false;
    }
    // check for row
    for(y=0;y<n;y++){
        if(mat[i][y]==num) return false;
    }
    // check for Sub-Grid
    int sx=(i/3)*3;
    int sy=(j/3)*3;
    for(x=sx;x<3+sx;x++){
        for(y=sy;y<3+sy;y++){
            if(mat[x][y]==num) return false;
        }
    }
    return true;
}

bool solveSudoku(int mat[][9],int i,int j,int n){
    //base case
    if(i==n){
        c++;
        //print solution
        for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){
                cout<<mat[x][y]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
        return true;
    }
    //case Row End
    if(j==n){
        return solveSudoku(mat,i+1,0,n);
    }
    //skip the filled cells
    if(mat[i][j]!=0) return solveSudoku(mat,i,j+1,n);

    for(int number=1;number<=n;number++){
        if(canPlace(mat,i,j,n,number)){
            mat[i][j]=number;
            bool solve=solveSudoku(mat,i,j+1,n);
            //if(solve) return true;
             mat[i][j]=0;
        }
       
    }

    //backtrack
    // mat[i][j]=0;
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
    int n=3;
    int mat[][9]={ {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
         {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
         {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
         {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
         {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
         {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
         {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
         {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
         {0, 0, 5, 2, 0, 6, 3, 0, 0} };
    bool ans=solveSudoku(mat,0,0,9);
    if(ans) cout<<"sol exist\n";
    else cout<<"sol does not exist\n";
    cout<<c<<"\n";
    return 0;
}