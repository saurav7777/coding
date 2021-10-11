#include<bits/stdc++.h>
#include<algorithm>
#include<cstring>
using namespace std;

int query(int *tree,int qs,int qe,int s,int e,int index){
	if(qe>=e && qs<=s) return tree[index]; // complete overlap
	if(qe<s || qs>e) return INT_MAX; // no overlap
	
	int mid=(s+e)/2;
	int left=query(tree,qs,qe,s,mid,2*index);
	int right=query(tree,qs,qe,mid+1,e,2*index +1);
	return min(left,right);
}

void update(int *tree,int s,int e,int index,int val,int i){
	if(i>e || i<s) return;

	if(s==e) {
		tree[index]=tree[index]+val;
		return;
	}

	int mid=(s+e)/2;
	update(tree,s,mid,2*index,val,i);
	update(tree,mid+1,e,2*index + 1,val,i);
	tree[index] = min(tree[2*index] ,tree[2*index + 1]);
	cout<<tree[index]<<"\n";
	
}

void rangeupdate(int *tree,int s,int e,int index,int val,int l,int r){
	if(l>s || r<s) return;

	if(s==e) {
		tree[index]=tree[index]+val;
		return;
	}

	int mid=(s+e)/2;
	update(tree,s,mid,2*index,val,l,r);
	update(tree,mid+1,e,2*index + 1,val,l,r);
	tree[index] = min(tree[2*index] ,tree[2*index + 1]);
	cout<<tree[index]<<"\n";
}

void buildtree(int *a,int s,int e,int *tree,int index){
	if(s==e){
		tree[index]=a[s];
	}else{
		int mid=(s+e)/2;
		buildtree(a,s,mid,tree,index*2);
		buildtree(a,mid+1,e,tree,2*index + 1);
		tree[index]=min(tree[2*index],tree[2*index +1]);
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif

	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int *segtree = new int[4*n +1];
	//memset(segtree,0,sizeof(segtree));
	for(int i=0;i<4*n + 1;i++){
		segtree[i]=0;
	}
	buildtree(arr,0,n-1,segtree,1);

    for(int i=0;i<4*n + 1;i++){
		cout<<segtree[i]<<" ";
	}
	cout<<"\n";
	//update
	update(segtree,0,n-1,1,10,3);

	for(int i=0;i<4*n + 1;i++){
		cout<<segtree[i]<<" ";
	}
	int k;
	cin>>k;
	while(k){
		cout<<"\n";
		int l,r;
		cin>>l>>r;
		cout<<query(segtree,l,r,0,n-1,1);
		k--;
	}
}