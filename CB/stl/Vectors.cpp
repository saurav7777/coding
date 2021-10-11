#include<bits/stdc++.h>
#include<algorithm>
#include<cstring>
using namespace std;


//comparator function
bool compare(int a,int b){
	return a>b;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif

	vector<int>a;
	vector<int>b(10,5); //10 numbers with value 5

	//insert some element O(N)
	b.insert(b.begin()+2,3,1);

	//erase some element O(n)
	//b.erase(b.begin()+1);
	b.erase(b.begin()+2,b.begin()+5);
	cout<<b.size()<<"\n";
	for(int i=0;i<b.size();i++) cout<<b[i]<<" ";
	cout<<"\n";
	//for(int x:b) cout<<x<<" ";

}