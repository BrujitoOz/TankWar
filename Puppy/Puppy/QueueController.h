#pragma once
#include "Base.h"
#include "LinkedQueue.h"
template<typename T>
class QueueController : public LinkedQueue<T>{
protected:
	Base* ObjBase;
public:
	QueueController() { ; }
	~QueueController() { ; }
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

};