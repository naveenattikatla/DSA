#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int Kadanes(vector<int>& nums){
	int maximum  = INT_MIN;
	int currentsum = 0;
	for(int i = 0 ; i < nums.size();i++){
		currentsum = max(currentsum+nums[i] , nums[i]);
		maximum = max(currentsum , maximum);
		
	}
	return maximum;
}

int main(){
	int n;
	cin>>n;
	vector<int> v(n); // -3 4 4 0 -13 -2 -4 6
	for(int i = 0 ; i < n ; i++)
		cin>>v[i];
	int result = Kadanes(v);
	cout<<"Largest Sum Contiguous Subarray is "<<result<<endl;
	return 0;
}