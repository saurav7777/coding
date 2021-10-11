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

	list<int>l;
	list<int>l1{1,2,3,4,5};
	list<string>l2{"apple","mango","orange","guava"};
	l2.push_front("watermelon");
	l2.push_back("pineapple");

	l2.sort();

	l2.reverse();

	cout<<l2.front()<<" "<<l2.back()<<"\n";

	for(string s:l2) cout<<s<<"-->";
	cout<<"\n";

	// l2.pop_back();
	// l2.pop_front();


	l2.push_back("kiwi");
	
	l2.remove("guava");

	l2.erase(l2.begin());

	auto it=l2.begin();
	it++;
    l2.insert(it,"lemon");
	list<string>::iterator itr;
	for(itr=l2.begin();itr!=l2.end();itr++) cout<<(*itr)<<"-->";

	cout<<"\n";
	cout<<l2.size();

}