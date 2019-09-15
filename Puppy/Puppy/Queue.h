#pragma once
#include "Node.h"
template <class T> class LinkedQueue {
protected: 
	int Size;
	Node<T>* Front;
	Node<T>* Back;
public:
	LinkedQueue() : Size(0), Front(nullptr), Back(nullptr) {}
	~LinkedQueue() {
		delete Front, Back;
		
	}
	void push(int value);
	int pop();
	int front();
	int back();
	int size();
	bool empty();
};

template <class T>
void LinkedQueue<T>::push(int value) {
	Node<T>* nodeaux = new Node<T>(value);
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
template <class T>
int LinkedQueue<T>::pop() {
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
template <class T>
int LinkedQueue<T>::front() {
	return Front->GetVal();
}
template <class T>
int LinkedQueue<T>::back() {
	return Back->GetVal();
}
template <class T>
int LinkedQueue<T>::size() {
	return Size;
}
template <class T>
bool LinkedQueue<T>::empty() {
	return Size == 0;
}