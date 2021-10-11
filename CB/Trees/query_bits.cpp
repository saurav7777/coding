#include<bits/stdc++.h>
#include<algorithm>
#include<cstring>
using namespace std;

int mod=1000000007;

int lazzy[100005]={0};

int ans=0;

int modp(int a ,int b){
	int res=1;
	while(b){
		if(b&1){
			res=(res*a)%mod;
		}
		a=(a*a)%mod;
		b=b>>1;
	}
	return res%mod;
}

void updateRangeLazy(int *tree,int ss,int se,int l,int r,int val,int index){
	if(lazzy[index]!=-1){
		tree[index]=((modp(2,se-ss+1) - 1 + mod)%mod * lazzy[index]%mod)%mod;
		if(ss!=se){
			lazzy[2*index]=lazzy[index];
			lazzy[2*index + 1]=lazzy[index];
		}
		lazzy[index]=-1;
	}

	// No Overlap
	if(ss>r || se<l) return;

	//complete Overlap
	if(ss>=l && se<=r){
		tree[index]=((modp(2,se-ss+1) - 1 + mod)%mod * val%mod)%mod;
		if(ss!=se){
			lazzy[2*index]=val;
			lazzy[2*index + 1]=val;
		}
		return;
	}
	//partial overlap
	int mid=(ss+se)/2;
	updateRangeLazy(tree,ss,mid,l,r,val,2*index);
	updateRangeLazy(tree,mid+1,se,l,r,val,2*index + 1);
	tree[index]=((tree[2*index]%mod *modp(2,se-mid)%mod)%mod + tree[2*index + 1]%mod)%mod;
}

int queryLazy(int *tree,int l,int r,int ss,int se,int index){
	if(lazzy[index]!=-1){
		tree[index]=((modp(2,se-ss+1)-1 + mod)%mod * lazzy[index]%mod)%mod;
		if(ss!=se){
			lazzy[2*index]=lazzy[index];
			lazzy[2*index + 1]=lazzy[index];
		}
		lazzy[index]=-1;
	}
	// No Overlap
	if(ss>r || se<l) return 0;	

	//complete Overlap
	if(ss>=l && se<=r){
		// if(tree[index]>0){
		// 	int range=(se-ss+1);
		// 	int t=(modp(2,range));
		// 	cout<<t<<" ";
		// 	t=(t-1 + mod)%mod;
		// 	int left=r-se;
		// 	int temp=modp(2,left)%mod;
		// 	cout<<temp<<" ";
		// 	t=(t%mod * temp)%mod;
		// 	//cout<<t<<" ";
		// 	ans=(ans%mod + t%mod)%mod;
		// 	return 0;
		// }
		return tree[index];
	}
	// if(ss==se) return 0;
	
	int mid=(ss+se)/2;
	int p1=queryLazy(tree,l,r,ss,mid,2*index);
	int p2=queryLazy(tree,l,r,mid+1,se,2*index + 1);
	if(r<=mid) return p1;

	return (p1*modp(2,min(se,r)-mid)%mod + p2)%mod;
}

void buildtree(int *a,int s,int e,int *tree,int index){

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif

	int n,q;
	cin>>n>>q;
	int arr[n];
	int *segtree = new int[4*n +1];	
	for(int i=0;i<4*n + 1;i++){
		segtree[i]=-1;
	}
    for(int i=0;i<4*n + 1;i++){
		cout<<segtree[i]<<" ";
	}
	cout<<"\n";

	while(q--){
		int x,l,r;
		ans=0;
		cin>>x>>l>>r;
		//cout<<x<<l<<r<<"\n";
		if(x == 2){
			ans=queryLazy(segtree,l,r,0,n-1,1);
			cout<<"query "<<l<<"-"<<r<<" "<<ans<<"\n";
		}else{
			//cout<<"update "<<l<<"-"<<r<<" \n";
			updateRangeLazy(segtree,0,n-1,l,r,x,1);
			
		}
	}
	for(int i=0;i<4*n + 1;i++){
		cout<<segtree[i]<<" ";
	}
}