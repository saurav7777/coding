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

	stack<int>st;
	queue<int>q;
	for(int i=1;i<=5;i++) {
		st.push(i);
		q.push(i);
	}
	while(!st.empty()) {
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<"\n";
	while(!q.empty()){
		cout<<q.front()<<",";
		q.pop();
	}

	priority_queue<int>pq;  //MAX-HEAP
	pq.push(1);
	pq.push(45);
	pq.push(23);
	pq.push(12);
	pq.push(67);
	cout<<"\n";
	while(!pq.empty()){
		cout<<pq.top()<<",";
		pq.pop();
	}

	priority_queue<int,vector<int>,greater<int>>pq1;  //MIN-HEAP
	pq1.push(1);
	pq1.push(45);
	pq1.push(23);
	pq1.push(12);
	pq1.push(67);
	cout<<"\n";
	while(!pq1.empty()){
		cout<<pq1.top()<<",";
		pq1.pop();
	}

	Person p1("aman",23);
	Person p2("gagan",24);
	Person p3("paras",25);
	Person p4("tanu",26);
	cout<<"\n";
	priority_queue<Person,vector<Person>,pcompare>pr;
	pr.push(p2);
	pr.push(p1);
	pr.push(p4);
	pr.push(p3);
	while(!pr.empty()){
		cout<<pr.top().name<<"\n";
		pr.pop();
	}

}