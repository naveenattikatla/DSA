#include<iostream>
using namespace std;
int cnt = 0;
struct stack{
	int data;
	stack* next;
};
stack* createNode(int data){
	cnt++;
	stack* node = new stack();
	node->data = data;
	node->next = NULL;
	return node;
}
stack*  push(stack* head , int data){
	stack* node = createNode(data);
	if(head==NULL){
		head = node;
		return head;
	}
	stack* temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = node;
	return head;
}
void display(stack* head){
	if(head ==NULL){
		cout<<"No elements"<<endl;
		return ;
	}
	stack* node = head;
	
	while(node!=NULL){
		cout<<node->data<<" ";
		node=node->next;
	}
	return ;
}
bool empty(stack* head){
	if(head==NULL)
		return true;
	return false;
}
int top(stack* head){
	if(head == NULL){
		cout<<"No elements"<<endl;
		return -1;
	}
	stack* node = head;
	while(node->next!=NULL){
		node= node->next;
	}
	return node->data;
}
int size(stack* head){
	return cnt;
}
stack* pop(stack* head){
	if(head== NULL){
		cout<<"No elements"<<endl;
		return head;
	}
	stack* node= head;
	stack* temp = NULL;
	while(node->next!=NULL){
		temp = node;
		node= node->next;
	}
	temp->next = NULL;
	delete(node);
	return head;
	
}
int  main(){
	stack* head = NULL;
	head =push(head,12);
	head =push(head,2);
	head =push(head,21);
	cout<<"top element "<<top(head)<<endl;
	cout<<"size is "<<size(head)<<endl;
	head = pop(head);
	display(head);
	return 0;
}