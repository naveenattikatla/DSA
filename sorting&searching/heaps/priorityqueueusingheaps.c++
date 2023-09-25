// priority queue implementation using maxheap

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
template <class T>
class Priority_queue{
	vector<T> v;
	int currentIndex = 0;
	public:	
		void push(T value){
			if(v.empty()){
				currentIndex = 0;
				v.push_back(value);
				
			}else{
				currentIndex++;
				v.push_back(value);
				int parent = floor(currentIndex - 1)/2;
				while(v[parent] < v[currentIndex] && parent >= 0){
					swap(v[currentIndex],v[parent]);
					parent = floor(currentIndex - 1)/2;	
				}
			}	
		}
		T top(){
			if(v.empty()){
				cout<<"No elements "<<endl;
				return -1;
			}
			else{
				return v[0];
			}
		}
		void  remove(){
			if(v.empty()){
				cout<<"No elements"<<endl;
				return ;
			}
			
			swap(v[0],v[currentIndex]);
			v.pop_back();
			currentIndex--;
			
		}
		int size(){
			return currentIndex + 1;
		}
		bool empty(){
			if(v.size() == 0){
				return true;
			}
			else
				return false;
		}
};
int main(){
	
	Priority_queue<int>  pq;
	pq.push(12);
	pq.push(13);
	pq.push(45);
	
	while(!pq.empty()){
		int result = pq.top();
		cout<<result<<" ";
		pq.remove();
	}
	
	return 0;
}