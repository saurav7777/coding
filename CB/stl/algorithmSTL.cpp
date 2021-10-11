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


	int arr[]={1,6,6,6,8,9,11};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<"index:"<<find(arr,arr+n,23)-arr<<"\n"; // find() returns a iterator

	// if(index==n){
	// 	cout<<"element is not found in array"<<"\n";
	// }else{
	// 	cout<<"elemnt is found in array"<<"\n";
	// }

	// return true or false
	bool present =binary_search(arr,arr+n,9);
	if(present){
		cout<<"present\n";
	}else{
		cout<<"not present\n";
	}

	//lower or upper bound return address of element
	auto lb= lower_bound(arr,arr+n,6);  //first element >=key
	cout<<"index of lower_bound:"<<lb-arr<<"\n";

	auto ub= upper_bound(arr,arr+n,6); // first element >key
	cout<<"index of upper_bound:"<<ub-arr<<"\n";

	cout<<"freq of key:"<<(ub-lb)<<"\n";

	//sort function
	int arr1[]={1,3,2,7,6,5};
	int size=sizeof(arr1)/sizeof(arr1[0]);

	sort(arr1,arr1+size,compare);
	for (int i = 0; i <size; i++)
	{
		cout<<arr1[i]<<" ";
	}

	//tokenizer a string

	char s[]="my name is saurav";
	char *ptr=strtok(s," ");
	cout<<ptr<<"\n";
	while(ptr!=0){
		cout<<ptr<<"\n";
		ptr=strtok(0," ");
		
	}

}