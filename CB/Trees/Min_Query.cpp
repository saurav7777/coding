#include<bits/stdc++.h>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;

int lazzy[100005]={0};

void buildtree(int *arr,int s,int e,int *tree,int index){
	if(s==e){
		tree[index]=arr[s];
		return;
	}

	int mid=(s+e)/2;
	buildtree(arr,s,mid,tree,index*2);
	buildtree(arr,mid+1,e,tree,2*index + 1);
	tree[index]=min(tree[2*index],tree[2*index + 1]);
	return;
}

int minQuery(int qs,int qe,int ss,int se,int *tree,int index){
	// if(qs==ss && qe==se) // Complete Overlap
	// 	return tree[index];

	// if(qs>se || qe<ss) //NO OverLap
	// 	return INT_MAX; 

	if(qe<ss || qs>se) return INT_MAX; // no overlap
	if(qs<=ss && qe>=se) return tree[index]; // complete overlap
	
	int mid=(ss+se)/2;
	int left=minQuery(qs,qe,ss,mid,tree,2*index);
	int right=minQuery(qs,qe,mid+1,se,tree,2*index + 1);
	return min(left,right);
}

void update(int *arr,int i,int ss,int se,int *tree,int index,int val){
	if(i>se || i<ss) //NO OverLap
		return ; 
	if(ss == se){ // Complete Overlap
		tree[index]=val;
		return;
	}

	int mid=(ss+se)/2;
	update(arr,i,ss,mid,tree,2*index,val);
	update(arr,i,mid+1,se,tree,2*index + 1,val);
	tree[index]=min(tree[2*index],tree[2*index + 1]);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif

	ll n,q;
	cin>>n>>q;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int *segtree = new int[4*n +1];
	for(int i=0;i<4*n + 1;i++){
		segtree[i]=0;
	}
	buildtree(arr,0,n-1,segtree,1);

	// for(int i=0;i<4*n + 1;i++){
	// 	cout<<segtree[i]<<" ";
	// }

	// cout<<"\n";

	while(q--){
		int c,x,y;
		cin>>c>>x>>y;
		if(c==1){
			cout<<minQuery(x-1,y-1,0,n-1,segtree,1)<<"\n";
		}else{
			update(arr,x-1,0,n-1,segtree,1,y);
		}
	}
	

}
