#include<iostream>
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

	string str;
	getline(cin,str);
	cout<<str<<"\n";
	str.push_back('H');
	cout<<str<<"\n";
	str.pop_back();
	cout<<str<<"\n";
	cout<<str.substr(1,5)<<"\n";

	cout<<str.find("aur")<<"\n";
	str.erase(2,2);
	cout<<str<<"\n";
	//cout<<string::npos;

}