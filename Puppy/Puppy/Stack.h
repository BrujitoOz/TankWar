#pragma once
// esta clase supuestamente sera para construir las torres enemigas
#include "Node.h"
class LinkedStack {
	// Solo usamos puntero a top que seria el plato(si tomamos el ejemplo de platos como pilas) que esta encima de todos
	Node* Top;
	int Size; // cantidad actuali de la pila
public:
	LinkedStack() : Top(nullptr), Size(0) {}
	~LinkedStack() {
		delete Top;
	}
	void push(int v) {
		Node* NodeAux = new Node(v);
		if (empty()) 
			Top = NodeAux; // si la pila esta vacia top apuntara al primer y unico nodo
		else {
			NodeAux->SetNext(Top); // el puntero de este nodo apunta asi mismo 
			Top = NodeAux; // Top guarda la direccion del nuevo nodo creado que es el primero
		}
		Size+=1; // se incrementa la cantidad
	}
	int top() {
		int val = -1; 
		if (!empty()) {
			val = Top->GetVal(); //muestra el valor del primer elemento de la pila
		}
		return val;
	}
	int pop() {
		int val = -1;
		if (!empty()) {
			val = Top->GetVal();
			Top = Top->GetNext();
			Size-=1;
		}
		return val; // lo mismo que el top, pero tambien elimina el primer elemento de la pila
	}
	int size() {
		return Size;
	}
	bool empty() {
		return Size == 0;
	}
};