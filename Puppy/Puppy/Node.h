#pragma once
class Node {
	int val;
	Node* next;
	Node(int val, Node* next = nullptr) : val(val), next(next) {}
	int GetVal() {
		return val;
	}
	void SetNext(Node* next) {
		this->next = next;
	}
	Node* GetNext() {
		return next;
	}
};