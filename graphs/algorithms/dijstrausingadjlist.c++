#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<cstdlib>
using namespace std;
class Solution{
	private :
		vector<bool> visited;
		queue<int> q;
		vector<int> traversal_array;
		int time = 0 ;
		vector<int> start_time;
		vector<int> end_time;
	public:
		vector<int> dist;
	public:
		int v;
		int e;
		vector<list<pair<int,int> > > adj_list;
		vector<vector<int> > adj_matrix;
		Solution(int n){
			this->v = n;
			int minedges = v - 1 ;
			int maxedges = (( v - 1 ) * v ) / 2 + (1)   - minedges;
			this->e = rand() % maxedges +  minedges;
			this->adj_list.resize(this->v);
			this->adj_matrix.resize(this->v,vector<int> (v));
		}
		void create_random_graph(){
			int src,dest;
			for(int i = 0 ; i < this->e ; i++){
				src  = rand() % this->v ;
				dest = rand() % this->v;
				while((src == dest) || this->adj_matrix[src][dest]){
					src  = rand() % this->v ;
				    dest = rand() % this->v;
				}
				int weight = rand() % 20 + 5;
				this->adj_list[src].push_back({ dest, weight});
			 	this->adj_list[dest].push_back({ src, weight});
			 	this->adj_matrix[src][dest] = 1;
			 	this->adj_matrix[dest][src] = 1;
			}
		}
		int numEdges(){
			return this->e;
		}
		void add_edge(int src , int dest , int weight){
			this->adj_list[src].push_back({ dest, weight});
			this->adj_list[dest].push_back({ src, weight});
		}
		void dijstra(int src){
			this->visited.resize(this->v,false);
			this->dist.resize(this->v,INT_MAX);
			this->dist[src] = 0;
			this->visited[src] = true;
			priority_queue<pair<int,int> , vector<pair<int,int> > , greater<pair<int,int> > > pq ;
			pq.push({ 0 , src});
			while(!pq.empty()){
				src = pq.top().second;
				this->visited[src] =true;
				pq.pop();	
				for(list<pair<int,int> >::iterator it = adj_list[src].begin(); it != adj_list[src].end();it++){
					if(!visited[it->first]){
						this->dist[it->first] = min(this->dist[it->first] , this->dist[src] + it->second );
						pq.push({ this->dist[it->first] , it->first}); 
						
					}
				}	
			}
			cout<<"Distance "<<endl;
			for(int i = 0 ; i < this->dist.size();i++){
				cout<<this->dist[i] << " ";
			}
		}
		void print_adj_list(){
			cout<<"adj.list "<<endl;
			for(int i = 0 ; i < this->adj_list.size();i++){
				cout<<i<<"->";
				for(list<pair<int,int> >::iterator it = adj_list[i].begin(); it != adj_list[i].end();it++){
					cout<<" ( "<<it->first<<" , "<< it->second<<" )";
					
				}
				cout<<endl;
			}
		}
};
int main(){
	int n;
	cin>>n;
	Solution s(n);
	s.create_random_graph();	
	
//	s.add_edge(0,1,3);
//	s.add_edge(0,2,4);
//	s.add_edge(2,3,4);
//	s.add_edge(1,3,2);
//	s.add_edge(1,4,10);
//	s.add_edge(3,4,2);
	
	s.print_adj_list();
	s.dijstra(0);

	return 0;
}