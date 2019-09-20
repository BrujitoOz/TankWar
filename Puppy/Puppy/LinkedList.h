#pragma once
#include "Node.h"
typedef unsigned int uint;
template <typename T> 
class LinkedList {
protected: 
	Node<T>* Head;
	uint Size;
public:
	LinkedList() : Head(nullptr), Size(0) {}
	~LinkedList() { delete Head; }
	void AddFirst(T* Element) {
		Node<T>* NodeNew = new Node<T>(*Element);
		if (IsEmpty()) {
			Head = NodeNew;
			NodeNew->SetNext(NodeNew);
		}		
		else {
			NodeNew->SetNext(Head);
			Node<T>* NodeLast = GetNode(Size - 1);
			NodeLast->SetNext(NodeNew);
			Head = NodeNew;
		}
		Size += 1;
	}
	void AddLast(T* Element) {
		Node<T>* NodeNew = new Node<T>(*Element);
		Node<T>* NodeAux = GetNode(Size - 1);
		NodeAux->SetNext(NodeNew);
		NodeNew->SetNext(Head);
		Size += 1;
	}
	void DeleteFirst() {
		if (!IsEmpty()) {
			Node<T>* NodeAux1 = Head;
			Node<T>* NodeAux2 = NodeAux1->GetNext();
			Node<T>* NodeLast = GetNode(Size - 1);
			NodeLast->SetNext(NodeAux2);
			Head = NodeAux2;
			NodeAux1 = nullptr;
			delete NodeAux1;
			Size -= 1;
		}
	}
	void DeleteLast() {
		if (!IsEmpty()) {
			Node<T>* NodeLast = GetNode(Size - 1);
			Node<T>* NodeAux = GetNode(Size - 2);
			NodeAux->SetNext(NodeLast->GetNext());
			delete NodeLast;
			Size -= 1;
		}
	}
	Node<T>* GetNode(int index) { // iterador
		uint cont = 0;
		Node<T>* NodeAux = Head;
		while (cont < index) {
			NodeAux = NodeAux->GetNext();
			cont += 1;
		}
		return NodeAux;
	}
	uint GetSize() { return Size; }
	bool IsEmpty() { return Size == 0; }
};