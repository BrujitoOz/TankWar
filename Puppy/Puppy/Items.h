#pragma once
#include "Base.h"
class Items:
	public Base
{
private: 
	int tipo, r, ge, b;
public:
	Items();
	void Cambiar_tipo(int nuevo);
	int Retornar_tipo();
	void Conf_tipo();
	void Dibujar(System::Drawing::Graphics ^ g);
	~Items();
};

Items::Items()
{
}
Items::~Items()
{
}
void Items::Cambiar_tipo(int nuevo)
{
	tipo = nuevo;
}
int Items::Retornar_tipo()
{
	return tipo;
}
void Items::Conf_tipo()
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
void Items::Dibujar(System::Drawing::Graphics ^ g) {
	Conf_tipo();
	System::Drawing::Color micolor = System::Drawing::Color::FromArgb(r, ge, b);
	System::Drawing::SolidBrush^ brocha = gcnew System::Drawing::SolidBrush(micolor);
	System::Drawing::Pen ^p = gcnew System::Drawing::Pen(micolor);
	if (!Eliminar &&  x > 0 && y > 0) {
		g->DrawEllipse(p, x, y, l, a);
		g->FillEllipse(brocha, x, y, l, a);
	}
}
//void Items::Dibujar(System::Drawing::Graphics ^ g) {}