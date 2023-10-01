#include<iostream>
using namespace std;
int add(int a ,int b){
	return a+b;
}
void printing_output( int (*fn) (int , int),int a,int b){
	int result = fn(a,b);
	cout<<"Sum of "<<a<<" and "<<b << " is "<<result<<endl;
}
int main(){
	int a,b;
	cin>>a>>b;
	printing_output(add,a,b); // passining fuction as argument
	int(*fn)(int ,int ) = add; // assigning function pointer to a varibale
	cout<<fn(a,b);
	return 0;
}
// we can pass function as an argument using functional pointer in c++;
// functional programming langauge
//1. we can pass functional as argument
//2. we can store function to a variable
//3. we can return function 