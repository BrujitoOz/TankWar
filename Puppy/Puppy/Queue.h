#pragma once
#include "Node.h"
template <class T> class LinkedQueue {
protected: 
	unsigned int Size;
	Node<T>* Front;
	Node<T>* Back;
public:
	LinkedQueue() : Size(0), Front(nullptr), Back(nullptr) {}
	~LinkedQueue() {
		delete Front, Back;
	}
	void push(T Element) {
		Node<T>* nodeaux = new Node<T>(Element);
		if (Size == 0) {
			Front = nodeaux;
			Back = nodeaux;
		}
		else {
			Back->SetNext(nodeaux);
			Back = nodeaux;
		}
		Size++;
	}
	void pop() {
		if (!empty()) {
			Node<T>* NodeAux = Front;
			Front = NodeAux->GetNext();
			delete NodeAux;
			Size -= 1;
		}
	}
	T front() {
		return Front->GetVal();
	}
	T back() {
		return Back->GetVal();
	}
	unsigned int size() {
		return Size;
	}
	bool empty() {
		return Size == 0;
	}
};