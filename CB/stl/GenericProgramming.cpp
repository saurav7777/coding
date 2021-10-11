
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int li;
int mod = 1000000007;

template<typename X>

//to get maximum b/w two numbers
const X& maxi(const X& a,const X& b){
	return a>b?a:b;
}


//to search a number 
template<typename X>
X search( X arr[],int size,X key){
	for(int i=0;i<size;i++){
		if(arr[i]==key){
			return i;
		}
	}
	return size;
}
//to get average of numbers
template<typename T>
T average(T* arr,int length){
	T sum(0);
	for(int i=0;i<length;i++){
		sum+=arr[i];
	}
	sum=sum/length;
	return sum;
}

class Cents{
public:
	int val;
public:
	Cents(int cents):val{cents}{

	}

	friend bool operator >(const Cents& a,const Cents& b){
		return a.val>b.val;
	}
	friend std::ostream& operator<< (std::ostream &out, const Cents &cents){
		out<<cents.val<<" cents";
		return out;
	}

	Cents& operator +=(const Cents& a){
		this->val+=a.val;
		return *this;
	}	

	Cents& operator /(const Cents& a){
		this->val/=a.val;
		return *this;
	}	
};

//create a custom container
template<class A,int size>
class customArray{
private:
	A arr[size];
public:
	A* getarray();

	A& operator[](int index){
		return arr[index];
	}
};

template<class A,int size>
A* customArray<A,size>:: getarray(){
	return arr;
}


//templates+iterators+comparators
template<class ForwardIterator,class T,class comparator>
ForwardIterator csearch(ForwardIterator start,ForwardIterator end,T key,comparator cmp){
	while(start!=end){
		if(cmp(*start,key)){
			return start;
		}
		start++;
	}
	return end;
}


class Book{
public:
	int price;
	string name;
	Book(){

	}
	Book(string name,int price){
		this->name=name;
		this->price=price;
	}
};


class compare{
public:
	bool operator()(Book a,Book b){
		if(b.name==a.name){
			return true;
		}else{
			return false;
		}
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
    int a,b;
    cin >> a>>b;
    cout<<maxi(a,b)<<"\n";
    
    string c,d;
    cin>>c>>d;
    cout<<maxi(c,d)<<"\n";


	Cents aman{10},paras{20};
	Cents bigger{maxi(aman,paras)};
   	cout<<bigger.val<<"\n";

   	
   	// int array1[]={ 5, 3, 2, 1, 4 };
    // cout <<"average="<< average(array1, 5) << '\n';
    // cout <<"search="<< search(array1, 5,1) << '\n';
 
    // double array2[]={ 3.12, 3.45, 9.23, 6.34 };
    // cout << "average="<<average(array2, 4) << '\n';
    // cout <<"search="<< search(array2, 4,9.23) << '\n';

    // Cents arr[]={Cents(10),Cents(20),Cents(30),Cents(40)};
    // cout << "cents average="<<average(arr, 4) << '\n';


    // customArray<int,12>cr;
    // for (int count=0; count < 12; ++count)
    //     cr[count] = count;
 
    // for (int count=11; count >= 0; --count)
    //     std::cout << cr[count] << " ";
    // std::cout << '\n';


    // list<int>l;
    // l.push_back(1);
    // l.push_back(3);
    // l.push_back(5);
    // l.push_back(9);
    // l.push_back(11);
    // cout<<(*csearch(l.begin(),l.end(),11));

   	list<Book>l;
    Book b1("java",100);
    Book b2("c++",200);
    Book b3("os",300);
    Book tofind("c++",200);
    l.push_back(b1);
    l.push_back(b2);
    l.push_back(b3);
    compare cmp;
 	if(cmp(b2,tofind)){
 		cout<<"book is found";
 	}else{
 		cout<<"boook is not found";
 	}
 	auto it=csearch(l.begin(),l.end(),tofind,cmp);
 	if(it!=l.end()){
 		cout<<"book is found";
 	}else{
 		cout<<"boook is not found";
 	}

 	
    return 0;
}
