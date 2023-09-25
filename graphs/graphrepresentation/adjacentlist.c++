#include<iostream>
#include<cstdlib>
#include<queue>
#include<vector>
#include<list>
using namespace std;
class Graph{
	public :
		int time  = 0;
		int v;
		int e;
		int cnt= 0 ;
		vector<int> traversal_array;
		vector<vector<int> > graph_matrix;
		vector<list<int> > graph_list;
	private :
		vector<bool> visited ;
		queue<int> q;
		vector<int> start_time;
		vector<int> end_time;
	public:
		Graph(int v){
			this->v = v;
			int minEdges = v - 1 ; 
			int maxEdges = ((v * ( v - 1) ) / 2 ) - minEdges + 1 ;
			this->e =  rand() %  maxEdges + minEdges; //  number of edges -> minimum 9 , maximum 45 if v is 10
			this->graph_matrix.resize(v,vector<int> (v,0)); // adj. matrix for graph
			this->graph_list.resize(v);
		}
	void add_edge(int src , int dest){
		this->graph_matrix[src][dest] = 1;
	}
	void create_random_graph(){
		// generting e edges
		int src, dest;
		for(int i = 0 ; i < this->e ; i++){
			src = rand() % this->v;
			dest = rand() % this->v;
			while(src == dest || graph_matrix[src][dest] == 1 ){
				 src = rand() % this->v;
			 	 dest = rand() % this->v;
			}
			graph_matrix[src][dest] = 1;
			graph_list[src].push_back(dest);
			
		}
	}
	int num_of_edges(){
		return this->e;
	}
	
	void printing_adjacent_list(){
		
		for(int i = 0 ; i < this->v;i++){
			cout<<i<<" ";
			while(!this->graph_list[i].empty()){
				cout<<this->graph_list[i].back()<<" ";
				this->graph_list[i].pop_back();
			}
			cout<<endl;
		}
	}
	
	
	
};
int main(){
	int n;
	cin>>n;
	Graph g(n);
	g.create_random_graph(); 
	g.printing_adjacent_list();
	
	return 0;
}