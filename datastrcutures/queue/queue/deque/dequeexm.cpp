// Given two positive integers N and K
// and an array F[] consisting of k positive integers.
// the Nth term of the recurrnce relation is given by
// FN= = FN-1 * FN-2*FN-3*.....*FN-K
// The task is to find out the Nth term of the given recurrence relation
#include<iostream>
#include<deque>
#include<cmath>
using namespace std;
long long int  NthElement(deque<int>& nums, int n){
	if( n  <= nums.size()){
		return nums[ n - 1];
	}
	int front , back; 
	for(int i = 4 ; i < n ; i++ ){	
		front = nums.front();
		back =  pow( nums.back(), 2) / front;
		nums.push_back(back);
		nums.pop_front();
	}
	return back;
	
}
int main(){
	int n,k;
	cin>>n>>k;
	deque<int> dq(k + 1);
	for(int i = 0 ; i <  k ; i++){
		cin>>dq[i];
	}
	dq[k] = 1;
	for(int i = 0 ; i < k ; i++)
		dq[k]*=dq[i];
	long long int result = NthElement(dq, n );
	cout<<"Nth term is "<<result<<endl;
	return 0;
}