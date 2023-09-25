#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
class compare{
	public :
		bool operator()(pair<int,int>&p1,pair<int,int>&p2){
			if(p1.second == p2.second){
				return p1.first > p2.first;
			}
			return p1.second > p2.second;
		}
};
void KmostElements(vector<int>& nums,int k){
	map<int,int> m;
	for(int i = 0 ; i < nums.size();i++){
		m[nums[i]]++;
	}
	for(map<int,int>::iterator i = m.begin();i!= m.end();i++){
		cout<<i->first<<" "<< i->second<<endl;
	}
	priority_queue<pair<int,int>,vector<pair<int,int> >,compare > p;
	for(map<int,int>::iterator it = m.begin();it!= m.end();it++){
		if(p.size() < k){
			p.push({it->first,it->second });
		}else{
			if(p.top().second < it->second){
				p.pop();
				p.push({it->first,it->second });		
			}
		}
	}
	cout<<"Elements in priority queue"<<endl;
	while(p.size()){
		cout<<p.top().first<<" "<<p.top().second<<endl;
		p.pop();
	}
	
}
int main(){
	int n,k;
	cin>>n>>k;
	vector<int> v(n);
	for(int i = 0 ; i < n ; i++){
		cin>>v[i];
	}
	KmostElements(v,k);
	
	return 0;
}