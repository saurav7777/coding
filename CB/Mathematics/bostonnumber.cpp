#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(int num){
	int sum1=0,sum2=0,temp=num;
	while(temp){
		sum1+=temp%10;
		//cout<<temp%10<<" ";
		temp=temp/10;

	}
	//cout<<"\n";

	for(int i=2;i*i <=num;i++){
		while(num%i == 0){
			temp=i;
			while(temp){
				sum2+=temp%10;
				//cout<<temp%10<<" ";
				temp=temp/10;

			}
			num=num/i;
			//cout<<i<<" ";
		}
	}
	if(num>2){
		temp=num;
		while(temp){
			sum2+=temp%10;
			//cout<<temp%10<<" ";
			temp=temp/10;

		}
	}
	//cout<<"\n";
	//cout<<sum1<<" "<<sum2<<"\n";
	if(sum1==sum2){
		cout<<"1\n";
	}else{
		cout<<"0\n";
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
#endif
	int num;
	cin>>num;

	solve(num);
	return 0;
}