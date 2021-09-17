#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int R,C;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

void floodFill(char mat[][50],int i,int j,char ch,char colour){
	//base case
	if(i<0 || i>=R || j<0 || j>=C) return;
	//Boundary condition
	if(mat[i][j]!= ch) return;

	//recursive call
	mat[i][j]=colour;
	for(int x=0;x<4;x++){
		floodFill(mat,i+dx[x],j+dy[x],ch,colour);
	}
}

void print(char mat[][50]){
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cout <<mat[i][j]<<" ";
		}
		cout<<"\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
	char mat[50][50];
	//int R,C;
	cin>>R>>C;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin>>mat[i][j];
		}
	}
	
	floodFill(mat,8,4,'.','r');
	floodFill(mat,0,0,'.','!');
	print(mat);

	return 0;
}

// 10 10
// ..........
// ...####...
// ...#..#...
// .########.
// .###...###
// .##.....##
// .#.......#
// ..#.....#.
// ...#...#..
// ....###...