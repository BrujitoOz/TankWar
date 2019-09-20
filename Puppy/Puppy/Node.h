#pragma once
template <typename T> 
class Node {
	 T Element;
	 Node* next;
public:
	Node(T Element) : Element(Element)  {}
	void SetElement(T Element) {
		this->Element = Element;
	}
	T GetElement() {
		return Element;
	}
	void SetNext(Node* next) {
		this->next = next;
	}
	Node* GetNext() {
		return next;
	}
};