#pragma once
#include "Node.h"
template <class T> class Pillation {
protected: 
	unsigned int Size;
	Node<T>* Top;
	//Node<T>* Back;

public:
	Pillation() :Size(0), Top(nullptr) {}
	~Pillation() { delete Top; }

	void push(T Element) {
		Node<T>* nodeaux = new Node<T>(Element);
		if (Size == 0) {
			Top = nodeaux;
		}
		else {
			nodeaux->SetNext(Top);
			Top = nodeaux;
		}
		Size++;
	}

	T pop() {
		
		if (!empty()) {
			Node<T>* NodeAux = Top;
			T value = NodeAux->GetVal(); // se guarda el valor con un auxiliar para devolverlo despues
			Top = NodeAux->GetNext();
			//delete NodeAux;
			Size -= 1;
			return value;
		}
		return nullptr;
	}
	T top() {
		return Top->GetVal();
	}
	unsigned int size() {
		return Size;
	}
	bool empty() {
		return Size == 0;
	}

};

