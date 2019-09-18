#pragma once
#include <iostream>
#include <string.h>
using namespace std;
using namespace System;
using namespace System::Drawing;
class Base{
protected:
	int x, y, dx, dy, l, a, vidas;
	bool Eliminar;
	char* PathIMG;
public:
	Base() = default;
	~Base() = default;
	void SetX(int X) { this->x = x; }
	void SetY(int y) { this->y = y; }
	void SetDX(int dx) { this->dx = dx; }
	void SetDY(int dy) { this->dy = dy;  }
	void SetL(int l) { this->l = l; }
	void SetA(int a) { this->a = a;  }
	void SetVidas(int vidas) { this->vidas = vidas; }
	void SetEliminar(bool Eliminar) { this->Eliminar = Eliminar; }
	void SetPathIMG(char* PathIMG) {
		this->PathIMG = new char[100];
		strcpy(this->PathIMG, PathIMG);
	}
	int GetX() { return x; }
	int GetY() { return y; }
	int GetDX() { return dx; }
	int GetDY() { return dy; }
	int GetL() { return l; }
	int GetA() { return a; }
	int GetVidas() { return vidas; }
	bool GetEliminar() { return Eliminar; }
	char* GetPathIMG() { return PathIMG; }
	// Hice varias funciones mover y dibujar distintas
	// esta es para que cuando una bala se salga de pantalla, se elimine de la lista
	// se podria usar con las balas enemigas por ejemplo
	// estaba pensando como seria con las balas del player porque usaran colas
	// o sea que al disparar sale la bala del primer nodo y ahí se sale de la cola
	// pero cuando sale de la cola solo se desconecta, asi que creo que igual tendremos que buscar como darle delete
	void MoveAndDelete(Graphics^ g) {
		x += dx;
		if (x + dx < g->VisibleClipBounds.Left || x + dx + a > g->VisibleClipBounds.Right) Eliminar = true;
		y += dy;
		if (y + dy < g->VisibleClipBounds.Top || y + dy + l > g->VisibleClipBounds.Bottom) Eliminar = true;
	}
	// Esta funcion es para que un objeto rebote al tocar un borde de la pantalla pero creo que no la usaremos
	void MoveRebound(Graphics^ g) {
		x += dx;
		if (x + dx < g->VisibleClipBounds.Left || x + dx + a > g->VisibleClipBounds.Right) dx *= -1;
		y += dy;
		if (y + dy < g->VisibleClipBounds.Top || y + dy + l > g->VisibleClipBounds.Bottom) dy *= -1;
	}
	// Pensaba colocar aca una funcion para que un objeto(enemigo) persiga a otro(piezas para construir)
	// no se aun si con este codigo baste o si tenemos que condicionar mas
	void MovePursuit(Base* obj1, Base* obj2) {
		if (obj1->x > obj2->GetX() + obj2->GetA()) obj1->dx = -1;
		if (obj1->x + obj1->GetA() < obj2->GetX()) obj1->dx = 1;
		if (obj1->y > obj2->GetY() + obj2->GetL()) obj1->dy = -1;
		if (obj1->y + obj1->GetL() < obj2->GetY()) obj1->dy = 1;
	}
	// esta funcion para dibujar circulos 
	// pensaba que seria buena idea pasarle el color por parametro
	// podemos usarlo para dibujar las balas, y piezas de construccion
	void DrawCircleFigure(Graphics^ g, Color MyColor) {
		SolidBrush^ brush = gcnew SolidBrush(MyColor);
		Pen^ p = gcnew Pen(MyColor);
		if (x > 0 && y > 0) {
			g->DrawEllipse(p, x, y, a, l);
			g->FillEllipse(brush, x, y, a, l);
		}
	}
	// para dibujar imagenes
	void DrawImage(Graphics^ g, Image^ img) {
		a = img->Width;
		l = img->Height;
		g->DrawImage(img, a, l);
	}
};