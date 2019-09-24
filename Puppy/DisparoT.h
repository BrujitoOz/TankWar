#pragma once
#include "Base.h"
class DisparoT :
	public Base
{
public:
	DisparoT();
	~DisparoT();
	void Dibujar(Graphics^ g, Image^ img);
	bool Mover(System::Drawing::Graphics^ g);
};


DisparoT::DisparoT()
{
	SetPathIMG("disparot.png");
}


DisparoT::~DisparoT()
{
}

void DisparoT::Dibujar(Graphics^ g, Image^ img) {

	g->DrawImage(img, x, y,a, l);
}

bool DisparoT::Mover(System::Drawing::Graphics^ g) {

	x += dx;
	if (x + dx < g->VisibleClipBounds.Left || x + dx + a > g->VisibleClipBounds.Right)
		return true;
	y += dy;
	if (y + dy < g->VisibleClipBounds.Top || y + dy + l > g->VisibleClipBounds.Bottom)
		return true;
	else
		return false;


}