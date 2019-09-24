#pragma once
#include "Base.h"
class Bala : // clase bala tiene los atributos de la clase Items
	public Base
{
private:
	int tipo, r, ge, b;
	int IndiceColumna, IndiceFila, FilaMax, ColumnaMax;
public:
	Bala();
	void Cambiar_tipo(int nuevo);
	int Retornar_tipo();
	void Conf_tipo();
	void Dibujar(Graphics^ g, Image^ img);
	bool Mover(System::Drawing::Graphics^ g);
	void SetIndiceColumna(int IndiceColumna);
	void SetIndiceFila(int IndiceFila);
	void SetColumnaMax(int ColumnaMax);
	void SetFilaMax(int FilaMax);
	int GetIndiceColumna();
	int GetIndiceFila();
	int GetFilaMax();
	int GetColumnaMax();
	~Bala();
};

Bala::Bala()
{
	SetPathIMG("balas.png");
	IndiceColumna = IndiceFila = 0;
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
void Bala::SetIndiceColumna(int IndiceColumna) {
	this->IndiceColumna = IndiceColumna;
}
void Bala::SetIndiceFila(int IndiceFila) {
	this->IndiceFila = IndiceFila;
}
void Bala::SetColumnaMax(int ColumnaMax) {
	this->ColumnaMax = ColumnaMax;
}
void Bala::SetFilaMax(int FilaMax) {
	this->FilaMax = FilaMax;
}
int Bala::GetIndiceColumna() {
	return IndiceColumna;
}
int Bala::GetIndiceFila() {
	return IndiceFila;
}
int Bala::GetFilaMax() {
	return FilaMax;
}
int Bala::GetColumnaMax() {
	return ColumnaMax;
}
void Bala::Conf_tipo()
{
	if (tipo == 1)
	{
		IndiceColumna = 1;
	}
	if (tipo == 2)
	{
		IndiceColumna = 2;
	}

	if (tipo == 3)
	{
		IndiceColumna = 0;
	}
	if (tipo == 4)
	{
		IndiceColumna = 3;
	}
}
void Bala::Dibujar(Graphics^ g, Image^ img2) {
	Conf_tipo();
	
	l = img2->Height / FilaMax;
	a = img2->Width / ColumnaMax;
	
	Rectangle porcionUsar = Rectangle(IndiceColumna * a, IndiceFila * l, a, l);
	Rectangle Destino = Rectangle(x, y, a, l);
	g->DrawImage(img2, Destino, porcionUsar, GraphicsUnit::Pixel);
}

bool Bala::Mover(System::Drawing::Graphics^ g) {

	x += dx;
	if (x + dx < g->VisibleClipBounds.Left || x + dx + a > g->VisibleClipBounds.Right)
		return true;
	y += dy;
	if (y + dy < g->VisibleClipBounds.Top || y + dy + l > g->VisibleClipBounds.Bottom)
		return true;
	else 
	return false;


}
