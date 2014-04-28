#pragma once
#include<iostream>
#include"Node.h"

using namespace std;

template<typename NodeType>
class List
{
private:
	int size;
	Node<NodeType>* head;
	Node<NodeType>* tail;
public:
	List(): head(nullptr), tail(nullptr), size(0){}

	Node<NodeType>* getHead() const {	return this->head ; }

	Node<NodeType>* getTail() const { return this->tail; }

	bool isEmpty() const { return this->size == 0; }

	void add(const NodeType &dat){
		if (isEmpty())
			this->head = this->tail = new Node<NodeType>(dat);
		else{
			this->tail->next = new Node<NodeType>(dat);
			this->tail = this->tail->next;
		}
		this->size++;
	}

	virtual void display()const/* = 0 ;*/{
		if (isEmpty()) cout << "list is empty" << endl;
		else{
			Node<NodeType>* temp;
			temp = this->head;
			while (temp != nullptr){
				cout << temp->data<<endl;
				temp = temp->next;
			}
		}
	}

	int getSize(){ return this->size; }

	bool deleteNode(Node<NodeType>* &n){
		if (n == nullptr || n->next == nullptr)// nothing to delete 
			return false;
		/*else if (n->next == nullptr){//its the only element in the list
			Node<NodeType>* temp = n;
			n = n->next;
			delete temp;
			this->size--;
			return true;
		}*/
		//else{
			Node<NodeType>* temp = n->next;
			n->data = n->next->data;
			n->next = n->next->next;
			delete temp;
			this->size--;
			return true;
		//}
		//return true;
	}


	void destroy(){
		if (!isEmpty()){
			Node<NodeType>* temp = this->head;
			while (temp != nullptr){
				this->head = temp->next;
				delete temp;
				temp = this->head;
				this->size--;
			}
		}
		else cout << "Cannot destroy emty list" << endl;
	}

	
	virtual ~List(){
		destroy();
	}

};

