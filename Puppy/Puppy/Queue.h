#pragma once
class LinkedQueue {
	
	int Size;
	Node* Front;
	Node* Back;
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
void LinkedQueue::push(int value) {
	Node* nodeaux = new Node(value);
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
int LinkedQueue::pop() {
	int value = -1;
	if (!empty()) {
		Node* nodeaux = Front; 
		value = nodeaux->GetVal(); 
		Front = nodeaux->GetNext(); 
		Size--;
	}
	else {
		//error
	}
	return value;
}
int LinkedQueue::front() {
	return Front->GetVal();
}
int LinkedQueue::back() {
	return Back->GetVal();
}
int LinkedQueue::size() {
	return Size;
}
bool LinkedQueue::empty() {
	return Size == 0;
}