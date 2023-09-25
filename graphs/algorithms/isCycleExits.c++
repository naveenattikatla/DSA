#include<iostream>
#include<cstdlib>
#include<queue>
#include<vector>
using namespace std;
class Graph{
	public :
		int time  = 0;
		int v;
		int e;
		int cnt= 0 ;
		vector<int> traversal_array;
		vector<vector<int> > graph_matrix;
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
			
		}
	}
	int num_of_edges(){
		return this->e;
	}
	void BFS(int node){
		this->visited.resize(v,false);
		if(visited[node]){
			return;
		}
	
		q.push(node);
		visited[node]= true;
		while(!q.empty()){
			node = q.front();
			cout<<node<<" ";
			q.pop();
			for(int i = 0  ; i < graph_matrix[node].size();i++){
				if(!visited[i] && graph_matrix[node][i]){
					visited[i] = true;
					q.push(i);
				}
			}
		}
	}
	void DFS(){
		this->start_time.resize(v);
		this->end_time.resize(v);
		this->visited.resize(v,false); 
		for(int i = 0 ; i < this->v;i++){
			if(!visited[i]){
				traverse_dfs(i);
			}
		}
		cout<<endl;
//		for(int i = 0;i < this->traversal_array.size();i++){
//			cout<<this->traversal_array[i]<<" ";
//		}
//		cout<<endl;
	}
	bool isCycleExist(){
		this->DFS();
		if(this->cnt){
			return true;
		}
		return false;
	}
	void traverse_dfs(int node){
		this->visited[node] =  true;
		this->traversal_array.push_back(node);
		this->start_time[node] = time;
		cout<<"start time of node "<<node<<" "<<this->start_time[node]<<endl;
		this->time++;
		int neighbour;
		int flag = true;
		for(neighbour = 0 ; neighbour < this->graph_matrix[node].size();neighbour++){
			if(graph_matrix[node][neighbour]){
				flag = false;
				if(!visited[neighbour]){
				cout<<"Tree edge "<<node<<" -- > "<<neighbour<<endl;
				this->traverse_dfs(neighbour);
				}else{
					
					if(this->end_time[neighbour] == 0){
						cout<<"back edge "<<node<<" --> "<<neighbour<<endl;
						this->cnt++;
					}
					else{
						if(this->end_time[neighbour] < this->start_time[node]){
							cout<<"cross edge "<<node<<" --> "<<neighbour<<endl;
						}else if(this->start_time[neighbour] > this->start_time[node]){
							cout<<"forward edge "<<node<<" --> "<<neighbour<<endl;
						}
					}
				}	
			}
		}
		this->end_time[node] = this->time;
		this->time++;
		cout<<"end time of node "<<node<<" "<<this->end_time[node]<<endl;	
	}
	void print_adj_matrix(){
		cout<<endl;
		for(int i = 0 ; i < this->v ; i++){
			for(int j = 0; j < this->graph_matrix[i].size() ; j++){
				cout<<this->graph_matrix[i][j]<<" ";
			}
			cout<<endl;
		}
	}	
};
int main(){
	int n;
	cin>>n;
	Graph g(n);
	// g.create_random_graph(); 
	
	g.add_edge(0,1);
	g.add_edge(1,2);
	g.add_edge(2,3);
	if(g.isCycleExist()){
		cout<<"cycle exits "<<endl;
	}else{
		cout<<"No cycle exits "<<endl;
	}
	
	// g.print_adj_matrix();
	// g.DFS();
	
	return 0;
}