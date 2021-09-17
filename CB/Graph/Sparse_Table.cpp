#include<bits/stdc++.h>
using namespace std;

#define INF 100000
typedef long long int ll;

const int n=100;

class sparseTable{
	vector<vector<int>> mat;
	int m;
	int n;
	vector<int>p2;
public:
	void init(int m,int n){
		this->m=m;
		this->n=n;
		mat.resize(n);
		p2.resize(n+1);
		for(int i=0;i<n;i++){
			mat[i].resize(m);
		}
		for(int i=2;i<=n;i++){
			p2[i]=p2[i/2]+1;
		}
	}

	void build(int a[]){
		for(int i=0;i<n;i++) mat[i][0] = a[i];
		for(int j=1;j<m;j++){
			for(int i=0; (i + (1<<(j))) <= n;i++){
				mat[i][j]= min(mat[i][j-1],mat[i+(1<<(j-1))][j-1]);
				cout<<mat[i][j]<<" ";
			}
			cout<<"\n";
		}
	}

	int query(int l ,int r){
		int pw= p2[r-l];
		return min(mat[l][pw],mat[r-(1<<pw)+1][pw]);
	}

};


int main() {
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

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	sparseTable st;
	int m =ceil(log2(n)) +1;
	cout<<m<<"\n";
	st.init(m,n);
	st.build(arr);
	cout<<st.query(2,8)<<"\n";
	return 0;
}