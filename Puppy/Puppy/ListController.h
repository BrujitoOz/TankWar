#pragma once
#include "Base.h" 
// Lo que decie era que ListController seria equivalente a la clase
// ArregloBase que usabamos en progra 2, entonces ListController debe tener un #include Base
// para usarlo como objeto para invocar las funciones genericas
#include "LinkedList.h"
template <typename T>
class ListController : public LinkedList<T> {
protected:
	Base* ObjBase; // ya no necesitamos int cantidad porque la lista tiene su funcion size()
public:
	ListController() { ObjBase = nullptr; }
	~ListController() { delete ObjBase; }
	void MoveAndDeleteAll(Graphics^ g) {
		for (int i = 0; i < GetSize(); i += 1)
			ObjBase->MoveAndDelete(g);
	}
	void MoveReboundAll(Graphics^ g) {
		for (int i = 0; i < GetSize(); i += 1)
			ObjBase->MoveRebound(g);
	}
	void MovePursuitAll(Base* obj1, Base* obj2) {
		for (int i = 0; i < GetSize(); i += 1)
			ObjBase->MovePursuit(obj1, obj2);
	}
	void DrawCircleFiguraAll(Graphics^ g, Color MyColor) {
		for (int i = 0; i < GetSize(); i += 1)
			ObjBase->DrawCircleFigure(g, MyColor);
	}
	void DrawImageAll(Graphics^ g, Image^ img) {
		for (int i = 0; i < GetSize(); i += 1)
			ObjBase->DrawImage(g, img);
	}
	// y asi podemos agregar mas funciones genericas para cada arreglo
};