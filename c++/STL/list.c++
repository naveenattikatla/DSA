#include <iostream>
#include<list>
#include<algorithm>
using namespace std;
bool Compare(const pair<int,int>& p1 ,const pair<int,int>&p2){
	return p1.second > p2.second;
}

int main() {
	list<pair<int,int>> values;
	values.push_back({ 2,3});
	values.push_back({ 4,2});
	values.push_back({-1,4});
	cout<<"Size is "<<values.size()<<endl;
	cout<<"Is empty values "<<values.empty()<<endl;
	
	
	cout<<"Sorting pairs usig second values descending order "<<endl;
	values.sort(Compare);
	cout<<"Values in list after sorting "<<endl;
	while(!values.empty()){
		pair<int,int> p = values.front();
		cout<<"("<<p.first<< " "<<p.second<<")"<<endl;
		values.pop_front();
	}
	
	return 0;
}