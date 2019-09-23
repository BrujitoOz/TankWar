#pragma once
#include "Base.h"
class Bala : // clase bala tiene los atributos de la clase Items
	public Base
{
private:
	int tipo, r, ge, b;
public:
	Bala();
	void Cambiar_tipo(int nuevo);
	int Retornar_tipo();
	void Conf_tipo();
	void Dibujar(System::Drawing::Graphics^ g);
	bool Mover(System::Drawing::Graphics^ g);
	~Bala();
};

Bala::Bala()
{
}
Bala::~Bala()
{
}
void Bala::Cambiar_tipo(int nuevo)
{
	tipo = nuevo;
}
int Bala::Retornar_tipo()
{
	return tipo;
}
void Bala::Conf_tipo()
{
	if (tipo == 1)
	{
		r = 0; ge = 255; b = 0;
	}
	if (tipo == 2)
	{
		r = 255; ge = 0; b = 255;
	}

	if (tipo == 3)
	{
		r = 255; ge = 255; b = 255;
	}
	if (tipo == 4)
	{
		r = 0; ge = 255; b = 255;
	}
}
void Bala::Dibujar(System::Drawing::Graphics^ g) {
	Conf_tipo();
	System::Drawing::Color micolor = System::Drawing::Color::FromArgb(r, ge, b);
	System::Drawing::SolidBrush^ brocha = gcnew System::Drawing::SolidBrush(micolor);
	System::Drawing::Pen^ p = gcnew System::Drawing::Pen(micolor);
	if (x > 0 && y > 0) {
		g->DrawEllipse(p, x, y, l, a);
		g->FillEllipse(brocha, x, y, l, a);
	}
}

bool Bala::Mover(System::Drawing::Graphics^ g) {

	x += dx;
	if (x + dx < g->VisibleClipBounds.Left || x + dx + a > g->VisibleClipBounds.Right)
		return true;
	y += dy;
	if (y + dy < g->VisibleClipBounds.Top || y + dy + l > g->VisibleClipBounds.Bottom)
		return true;



}
