#pragma once
 template <class T> class Node {
 protected:
	 T val;
	 Node<T>* next;
public:
	//T val;
	//Node* next;
	Node(T val, Node<T>* next = nullptr) : val(val), next(next) {}
	T GetVal() {
		return val;
	}
	void SetNext(Node* next) {
		this->next = next;
	}
	Node<T>* GetNext() {
		return next;
	}
};