#pragma once
#include "Node.h"
template <class T> 
class LinkedQueue {
protected:
	int Size;
	Node<T>* Front;
	Node<T>* Back;
public:
	LinkedQueue() : Size(0), Front(nullptr), Back(nullptr) {}
	~LinkedQueue() {
		delete Front, Back;
	}
	void push(int Element) {
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
	int pop() {
		int value = -1;
		if (!empty()) {
			Node<T>* nodeaux = Front;
			value = nodeaux->GetVal();
			Front = nodeaux->GetNext();
			Size--;
		}
		else {
			//erro
		}
		return value;
	}
	int front() {
		return Front->GetVal();
	}
	int back() {
		return Back->GetVal();
	}
	int size() {
		return Size;
	}
	bool empty() {
		return Size == 0;
	}
};