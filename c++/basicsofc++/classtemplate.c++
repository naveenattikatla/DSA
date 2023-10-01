#include<iostream>
#include<vector>
using namespace std;
template <class T = int >
class students{
	private:
		string name = "IIIT SKLM";
		int total ;
		vector<T> marks;
	public:
		students(){}
		students(int n){total = n;}
	void add(T mark){
		marks.push_back(mark);
	}
	void getMarks(){
		for(int  i = 0 ; i < marks.size();i++){
			cout<<marks[i]<<" ";
		}
	}
};
int main(){
	students<float> s;
	s.add(12.3);
	s.add(13.4);
	s.getMarks();
	return 0;
}