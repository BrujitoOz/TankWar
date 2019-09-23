#pragma once
#include "Base.h"
using namespace System;
using namespace System::Drawing;
class Enemigo : public Base {
	
public:
	Enemigo();
	~Enemigo();
	void DisminuirVida();
	void Move(Graphics^ g);
	void Draw(Graphics ^esp);
};
Enemigo::Enemigo() {
}
Enemigo::~Enemigo() {
}
void Enemigo::DisminuirVida() {
	vidas -= 1;
	if (vidas == 0)
		Eliminar = true;
}
void Enemigo::Move(System::Drawing::Graphics^ g) {
	y += dy;
	if (y < g->VisibleClipBounds.Top || y + l > g->VisibleClipBounds.Bottom)
		dy *= -1;
	x += dx;
	if (x < g->VisibleClipBounds.Left || x + a > g->VisibleClipBounds.Right)
		dx *= -1;
}
void Enemigo::Draw(Graphics^ esp) {
	Color micolor = Color::FromArgb(192,32,12);
	SolidBrush^ brocha = gcnew SolidBrush(micolor);
	Pen^ p = gcnew Pen(micolor, 5);
	esp->DrawEllipse(p, x, y, a, l);
	esp->FillEllipse(brocha, x, y, a, l);
}