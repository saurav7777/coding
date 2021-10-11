#include<bits/stdc++.h>
#include<algorithm>
#include<cstring>
using namespace std;

class Person{
public:
	int age;
	string name;
	Person(){

	}
	Person(string name,int age){
		this->age=age;
		this->name=name;
	}
};

class pcompare{
public:
	bool operator()(Person p1,Person p2){
		return p1.age > p2.age;
	}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif

	map<string,int>m;
	m.insert(make_pair("apple",20));
	pair<string,int>p;
	p.first="mango";
	p.second=30;
	m.insert(p);
	m["banana"]=20;

	map<string,int>::iterator itr;
	for(itr=m.begin();itr!=m.end();itr++){
		cout<<(*itr).first<<" "<<itr->second<<"\n";
	}

	if(m.find("mango")!=m.end()) cout<<"present\n";
	else cout<<"Not Present\n";

	m.erase("mango");

	cout<<"\n";
	multimap<string,int>m1;
	m1.insert(make_pair("A",1));
	m1.insert(make_pair("A",2));
	m1.insert(make_pair("A",1));
	for(auto p:m1){
		cout<<p.first<<" "<<p.second<<"\n";
	}

	cout<<"\n";
	set<int>s;
	s.insert(13);
	s.insert(10);
	s.insert(45);
	set<int>::iterator it1;
	for(it1=s.begin();it1!=s.end();it1++) 
		cout<<*it1<<"\n";
}