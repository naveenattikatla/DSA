#include <iostream>
#include<unordered_map>
using namespace std;
int main() {
	unordered_map<int,int> m;
	m.insert({1 ,2});
	m.insert({2 ,3});
	m.insert({-1,-4});
	m.insert(make_pair(3,5));
	cout<<"Size is "<<m.size()<<endl;
	
	unordered_map<int,int>::iterator it;
	for(it = m.begin() ; it != m.end() ; it++)
		cout<<"("<<it->first<<","<<it->second<<")"<<endl;
	cout<<"Is map empty "<<m.empty()<<endl;


	return 0;
}