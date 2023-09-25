#include <iostream> 
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
int cnt = 0;
using namespace std;
struct Node{
	int data ;
	Node* next;
};
Node* createNode(int data){
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	return temp;
}
Node* insert(Node* head , int data){
	cnt++;
	Node* node = createNode(data);
	if(head == NULL){
		head = node;
		
		return head;
	}
	Node* temp = head;
	while(temp->next != NULL){
		temp =  temp->next;
	}
	temp->next = node;
	return head;
		
}
void display(Node* head){
	if(head ==NULL){
		cout<<"No Elements in linked list to show"<<endl;
		return ;
	}
	Node* node = head;
	while(node!=NULL){
		cout<<node->data<<" ";
		node = node->next;
	}
	return ;
}
Node* deleteLst(Node* head){
	
	if(head == NULL){
		cout<<"NO elements in linked list to delete"<<endl;
		return head;
	}
	Node* node = head;
	Node* temp = NULL;
	while(node->next !=NULL){
		temp = node;
		node = node->next;
	}
	temp->next = NULL;
	delete(node);
	return head;
	
}
Node* deleteKth(Node* head,int k){
	if(head == NULL || cnt < k){
		cout<<"NO elements in linked list to delete"<<endl;
		return head;
	}
	cnt--;
	if( k == 1 ){
		Node * temp = head;
		head = head->next;
		delete(temp);
		return head;
	}
	if(k == cnt){
		Node* temp = deleteLst(head);
		return temp;
	}
	Node* node= head;
	Node* temp;
	for(int i = 1 ; i < k-1 ;i++ ){
		node = node->next;
	}
	temp = node->next;
	node->next =  node->next->next;
	delete(temp);
	return head;
	
}
int main() {
	Node* head = NULL;
	head = insert(head,1);
	
	display(head);
	
	cout<<endl;
	
	head = deleteKth(head , 1);

	
	display(head);
	cout<<endl;
	cout<<"count is "<<cnt<<endl;
	return 0;
}