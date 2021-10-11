#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class node{
public:
	vector<int>v;
};

int ans;
int num=0;

node merge(node a,node b,node c){
	int bs=b.v.size();
	int cs=c.v.size();
	int i=0,j=0;
	while(i<bs && j<cs){
		if(b.v[i] < c.v[j]){
			a.v.push_back(b.v[i++]);

		}else{
			a.v.push_back(c.v[j++]);
		}
	}
	while(i<bs){
		a.v.push_back(b.v[i++]);
	}
	while(j<cs){
		a.v.push_back(c.v[j++]);
	}
	return a;
}

void buildtree(int *arr,int s,int e,node *tree,int index){
	if(s==e){
		tree[index].v.push_back(arr[s]);
		return;
	}

	int mid=(s+e)/2;
	buildtree(arr,s,mid,tree,index*2);
	buildtree(arr,mid+1,e,tree,2*index + 1);
	tree[index]=merge(tree[index],tree[index*2],tree[2*index + 1]);
	// tree[index]=max(tree[2*index],tree[2*index + 1]);
	return;
}

int maxQuery(int qs,int qe,int ss,int se,node *tree,int index){
	// if(qs==ss && qe==se) // Complete Overlap
	// 	return tree[index];

	// if(qs>se || qe<ss) //NO OverLap
	// 	return INT_MAX; 

	if(qe<ss || qs>se) return INT_MIN; // no overlap
	if(qs<=ss && qe>=se){
		int temp=lower_bound(tree[index].v.begin(),tree[index].v.end(),num)- tree[index].v.begin(); // complete overlap
		ans +=(tree[index].v.size()-temp);
		return 0;
	}
	
	int mid=(ss+se)/2;
	int left=maxQuery(qs,qe,ss,mid,tree,2*index);
	int right=maxQuery(qs,qe,mid+1,se,tree,2*index + 1);
	return 0;
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
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	node *segtree = new node[4*n +1];
	
	buildtree(arr,0,n-1,segtree,1);

	// for(int i=0;i<4*n + 1;i++){
	// 	for(int j=0;j<segtree[i].v.size();j++){
	// 		cout<<segtree[i].v[j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	// cout<<"\n";
	cin>>q;
	int d=0;
	while(q--){
		int c,x,y;
		cin>>x>>y>>c;
		ans=d;
		num=c;
		maxQuery(x-1,y-1,0,n-1,segtree,1);
		cout<<ans<<"\n";
	}
	

}
