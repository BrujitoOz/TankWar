#pragma once
#include "Base.h"
#include "Node.h"
#include "Iterator.h"
//#include <functional>
using namespace std;
template <class T> class LinkedList {
protected: 
	Node<T>* Head;
	int Size;
public:
	LinkedList() : Head(nullptr), Size(0) {}
	~LinkedList() {
		delete Head;
	}
	int	size() {
		return Size;
	}
	bool empty() {
		return Size == 0;
	}
	void AddFirst(T v) {
		Node<T>* NodeAux = new Node<T>(v);
		NodeAux->SetNext(Head);
		if (NodeAux != nullptr) {
			Head = NodeAux;
			Size++;
		}
	}
	void DeleteFirst() {
		if (Size > 0) {
			Node<T>* NodeAux = Head;
			Head = Head->GetNext();
			delete NodeAux;
			Size-=1;
		}
	}
	T GetValueFirst() {
		return Head->GetVal();
	}
	T GetTheLast() {
		Node<T> *p = Head;
		while (p->GetNext()!nullptr) p = p->SetNext();
		return p;
	}
	void AddEnd(T v)
	{
		Node<T>* last = this->GetTheLast();
		last->SetNext(new Node<T>(v));
		Size++;
	}
	void DeleteEnd() {
		if (Size > 0) {
			Node<T>* NodeAux = Head;
			
			while (NodeAux->GetNext()->GetNext() != nullptr)
				NodeAux = NodeAux->SetNext();
			Node<T>* NodeAux2 = NodeAux->GetNext();
			NodeAux->SetNext(NodeAux2->SetNext());
			delete NodeAux2;
			Size --;
		}
	}
	void AddPos(Node<T> previus, T v)
	{
		Node<T>* NodeAux;
		NodeAux = new Node<T>(v);
		NodeAux->SetNext(previus->SetNext());
		previus->SetNext(NodeAux);
		Size++;
	}
	void MoveAll(System::Drawing::Graphics^ g)
	{
		Node<T> *aux = Head;
		for (int i = 0; i < Size; i++)
		{
			aux->GetNext
		}
	}
	Iterator<T> Begin() {
		return Iterator<T>(0, Head);
	}
	Iterator<T> End() {
		return Iterator<T>(Size, nullptr);
	}
	

};
 
/*template <class T>
void DoTask(LinkedList<T> Aux, function<T> F) {
	for (Iterator<T> It = Aux.Begin(); It != Aux.End(); It++)
	{
		T el = *It;
		F(el);
	}
}*/