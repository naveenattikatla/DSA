#include<bits/stdc++.h>
using namespace std;
class Solution{
	private :
		vector<bool> visited;
		queue<int> q;
		vector<int> traversal_array;
	protected:
		int time = 0 ;
		vector<int> start_time;
		vector<int> end_time;
	public:
		int v;
		int e;
		vector<list<int> > adj_list;
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
				this->adj_list[src].push_back(dest);
			 	// this->adj_list[dest].push_back(src);
			 	this->adj_matrix[src][dest] = 1;
			 	// this->adj_matrix[dest][src] = 1;
			}
		}
		int numEdges(){
			return this->e;
		}
		void add_edge(int src,int dest){
			this->adj_list[src].push_back(dest);
			// this->adj_list[dest].push_back(src); 
		}
		void bfs(){
			visited.resize(this->v,false);
			cout<<"BFS Traversal "<<endl;
			for(int i = 0 ; i < this->adj_list.size();i++){
				if(!visited[i])
					bfs_traversal(i);
			}
			cout<<endl;
			this->visited.clear();
		}
		void bfs_traversal(int src){
			
			visited[src] = true;
			this->q.push(src);
			cout<<this->q.front()<< " ";
			while(!q.empty()){
				src = this->q.front();
				this->q.pop();
				for(list<int>::iterator it = adj_list[src].begin(); it != adj_list[src].end();it++){
					if(!visited[*it]){
						visited[*it] = true;
						cout<<*it<< " ";
						q.push(*it);
					}
			    }
			}
		}
		void dfs(){
			visited.resize(this->v,false);
			this->start_time.resize(this->v , 0);
			this->end_time.resize(this->v , 0);
			for(int i = 0 ; i < this->adj_list.size();i++){
				if(!visited[i])
					dfs_traversal(i);
			}
			cout<<"DFS traversal "<<endl;
			for(int i = 0 ; i < this->traversal_array.size();i++){
				cout<<this->traversal_array[i]<<" ";
			}
			this->traversal_array.clear();
			this->visited.clear();
		}
		void dfs_traversal(int src){
			visited[src] = true;
			this->start_time[src] = this->time;
			cout<<"start time of "<<src<< " is "<<this->start_time[src]<<endl;
			this->time++;
			this->traversal_array.push_back(src);
			for(list<int>::iterator it = adj_list[src].begin(); it != adj_list[src].end();it++){
				if(!visited[*it]){
					dfs_traversal(*it);
				}else{
					if(this->end_time[*it] == 0){
						cout<<"back edge from "<<src<<" to "<<*it<<endl;
					}else{
						if(this->end_time[*it] > this->start_time[src]){
							cout<<"forward edge from "<<src<<" to "<<*it<<endl;
						}else{
							cout<<"cross edge from "<<src<<" to "<<*it<<endl;
						}
					}
				}
			}
			this->end_time[src]= this->time;
			cout<<"end time of "<<src<< " is "<<this->end_time[src]<<endl;
			this->time++;
		}
		void print_adj_list(){
			cout<<"adj.list "<<endl;
			for(int i = 0 ; i < this->adj_list.size();i++){
				cout<<i<<"->";
				for(list<int>::iterator it = adj_list[i].begin(); it != adj_list[i].end();it++){
					cout<<*it<<" ";
					
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
	s.print_adj_list();
	
	s.bfs();
	s.dfs();

	return 0;
}