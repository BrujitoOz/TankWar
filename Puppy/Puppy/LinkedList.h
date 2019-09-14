#pragma once
#include "Node.h"
using namespace std;
class LinkedList {
	Node* Head;
	int Size;
public:
	LinkedList() : Head(nullptr), Size(0) {}
	~LinkedList() {
		delete Head;
	}
	int	size() {
		return Size;
	}
	bool empty() {
		return Size == 0;
	}
	void AddFirst(int v) {
		Node* NodeAux = new Node(v);
		NodeAux->SetNext(Head);
		if (NodeAux != nullptr) {
			Head = NodeAux;
			Size++;
		}
	}
	void DeleteFirst() {
		if (Size > 0) {
			Node* NodeAux = Head;
			Head = Head->GetNext();
			delete NodeAux;
			Size-=1;
		}
	}
	int GetValueFirst() {
		return Head->GetVal();
	}
};