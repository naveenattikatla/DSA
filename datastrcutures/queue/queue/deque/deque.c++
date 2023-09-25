#include<iostream>
#include<deque>
using namespace std;
int main(){
	// deque supports random access iterators
	deque<int> dq;  //  default constructor 
	dq.push_back(12); // to push element at back of deque
	dq.push_front(13); // to push element at front od deque
	dq.push_back(14);
	dq.push_back(15);
	
	dq.pop_back(); // removing elements from back of deque
	dq.pop_front(); // removing elements from front of deque
	
	cout<<dq.size()<<endl; // size of deque
	
	cout<<dq.empty()<<endl; // return 1 if deque is empty ,otherwise 0
	
	
	for(deque<int>::iterator it = dq.begin() ; it!= dq.end() ; it++){
		cout<<*it<<" ";
	}
    cout<<endl;
    for(deque<int>::reverse_iterator it = dq.rbegin() ; it!=dq.rend();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	cout<<"deque "<<endl;
	
	return 0;
}
// Note : end pointes next location of a container