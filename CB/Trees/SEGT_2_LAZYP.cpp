#include<bits/stdc++.h>
#include<algorithm>
#include<cstring>
using namespace std;

int lazzy[1000]={0};

void updateRangeLazy(int *tree,int ss,int se,int l,int r,int val,int index){
	//before going down resolve lazy value if it exist
	if(lazzy[index]!=0){
		tree[index]+=lazzy[index];
		//check for non leafnode
		if(ss!=se){
			lazzy[2*index]+=lazzy[index];
			lazzy[2*index + 1]+=lazzy[index];
		}
		lazzy[index]=0;
	}

	//Base case = No OverLap
	if(ss>r || se<l){
		return;
	}

	//Complete Overlap
	if(ss>=l && se<=r){
		tree[index]+=val;
		if(ss!=se){
			lazzy[2*index] +=val;
			lazzy[2*index +1 ] +=val;
		}
		return;
	}

	//Recursive Case
	int mid=(ss+se)/2;
	updateRangeLazy(tree,ss,mid,l,r,val,2*index);
	updateRangeLazy(tree,mid+1,se,l,r,val,2*index + 1);
	tree[index]=min(tree[2*index],tree[2*index + 1]);

}

int queryLazy(int *tree,int qs,int qe,int ss,int se,int index){
	//before going down resolve lazy value if it exist
	if(lazzy[index]!=0){
		tree[index]+=lazzy[index];
		//check for non leafnode
		if(ss!=se){
			lazzy[2*index] +=lazzy[index];
			lazzy[2*index + 1] +=lazzy[index];
		}
		lazzy[index]=0;
	}
	if(qe<ss || qs>se) return INT_MAX; // no overlap
	if(qs<=ss && qe>=se) return tree[index]; // complete overlap
	
	int mid=(ss+se)/2;
	int left=queryLazy(tree,qs,qe,ss,mid,2*index);
	int right=queryLazy(tree,qs,qe,mid+1,se,2*index +1);
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
	//cout<<tree[index]<<"\n";
	
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
	updateRangeLazy(segtree,0,n-1,0,2,10,1);
	updateRangeLazy(segtree,0,n-1,0,4,10,1);
	cout<<"Q1 1-1 "<<queryLazy(segtree,1,1,0,n-1,1)<<"\n";
	updateRangeLazy(segtree,0,n-1,3,4,10,1);
	updateRangeLazy(segtree,0,n-1,4,5,10,1);
	cout<<"Q1 3-5 "<<queryLazy(segtree,3,5,0,n-1,1)<<"\n";
	for(int i=0;i<4*n + 1;i++){
		cout<<segtree[i]<<" ";
	}

}