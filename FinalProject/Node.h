#pragma once
template<typename NodeType> class List;

template<typename NodeType>
class Node
{
	friend class List<NodeType>;// made list a friend so it can access the private attributes of node
private:
	NodeType data;
	Node* next;
public:
	Node(NodeType d): data(d), next(nullptr){
	}
	NodeType getData()const{//get data
		return this->data;
	}
	Node* getNext()const{// get pointer to Next
		return this->next;
	}
	virtual ~Node(){

	}
};