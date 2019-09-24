#pragma once
#include "Node.h"
template < class T>
class Iterator
{ 
	Node<T> *aux;
	unsigned int pos;
	 
public:
	Iterator(unsigned int pos, Node<T>* aux) : pos(pos), aux(aux) {}
	//~Iterator() {}
	void operator++ ()
	{
		pos++;
		aux = aux->next;
	}
	bool operator!= (Iterator x) {
		return pos != x.pos;
	}
	T operator* () {
		return aux->val;
	}

	int getPos() {
		return pos;
	}

};

