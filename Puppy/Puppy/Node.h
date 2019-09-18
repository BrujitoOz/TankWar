#pragma once
template <class T> class Node {
	 T ElementOfNode;
	 Node<T>* next;
public:
	Node(T ElementOfNode, Node<T>* next = nullptr) : ElementOfNode(ElementOfNode), next(next) {}
	T GetVal() {
		return ElementOfNode;
	}
	void SetNext(Node* next) {
		this->next = next;
	}
	Node<T>* GetNext() {
		return next;
	}
};