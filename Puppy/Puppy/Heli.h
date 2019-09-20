#pragma once
#include "Base.h"
class Heli :
	public Base
{
	int IndiceColumna, IndiceFila, FilaMax, ColumnaMax;
public:
	Heli();
	~Heli();

	void SetIndiceColumna(int IndiceColumna);
	void SetIndiceFila(int IndiceFila);
	void SetColumnaMax(int ColumnaMax);
	void SetFilaMax(int FilaMax);
	int GetIndiceColumna();
	int GetIndiceFila();
	int GetFilaMax();
	int GetColumnaMax();
	void Draw(Graphics^ g, Image^ img);
	void Move(Graphics^ g);
};
Heli::Heli()
{
	SetPathIMG("Helicop.png");
	IndiceColumna = IndiceFila = 0;
}


Heli::~Heli()
{
}

void Heli::SetIndiceColumna(int IndiceColumna) {
	this->IndiceColumna = IndiceColumna;
}
void Heli::SetIndiceFila(int IndiceFila) {
	this->IndiceFila = IndiceFila;
}
void Heli::SetColumnaMax(int ColumnaMax) {
	this->ColumnaMax = ColumnaMax;
}
void Heli::SetFilaMax(int FilaMax) {
	this->FilaMax = FilaMax;
}
int Heli::GetIndiceColumna() {
	return IndiceColumna;
}
int Heli::GetIndiceFila() {
	return IndiceFila;
}
int Heli::GetFilaMax() {
	return FilaMax;
}
int Heli::GetColumnaMax() {
	return ColumnaMax;
}
void Heli::Draw(Graphics^ g, Image^ img) {
	l = img->Height / FilaMax;
	a = img->Width / ColumnaMax;
	Rectangle porcionUsar = Rectangle(IndiceColumna * a, IndiceFila * l, a, l);
	Rectangle Destino = Rectangle(x, y, a, l);
	g->DrawImage(img, Destino, porcionUsar, GraphicsUnit::Pixel);
}
void Heli::Move(System::Drawing::Graphics^ g)
{
	y += dy;
	IndiceFila++;
	if (IndiceFila == 4) IndiceFila = 0;
	if (y < g->VisibleClipBounds.Top || y + l > g->VisibleClipBounds.Bottom)
		dy *= -1;
	x += dx;
	if (x < g->VisibleClipBounds.Left || x + a > g->VisibleClipBounds.Right)
		dx *= -1;
}