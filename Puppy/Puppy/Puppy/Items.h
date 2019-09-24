#pragma once
#include "Base.h"
class Items:
	public Base
{
private: 
	int tipo, r, ge, b;
	int IndiceColumna, IndiceFila, FilaMax, ColumnaMax;
public:
	Items();
	void SetIndiceColumna(int IndiceColumna);
	void SetIndiceFila(int IndiceFila);
	void SetColumnaMax(int ColumnaMax);
	void SetFilaMax(int FilaMax);
	int GetIndiceColumna();
	int GetIndiceFila();
	int GetFilaMax();
	int GetColumnaMax();
	void Cambiar_tipo(int nuevo);
	int Retornar_tipo();
	void Conf_tipo();
	void Dibujar(Graphics^ g, Image^ img);
	~Items();
};

Items::Items()
{
	SetPathIMG("items.png");
	IndiceColumna = IndiceFila = 0;
}
Items::~Items()
{
}
void Items::SetIndiceColumna(int IndiceColumna) {
	this->IndiceColumna = IndiceColumna;
}
void Items::SetIndiceFila(int IndiceFila) {
	this->IndiceFila = IndiceFila;
}
void Items::SetColumnaMax(int ColumnaMax) {
	this->ColumnaMax = ColumnaMax;
}
void Items::SetFilaMax(int FilaMax) {
	this->FilaMax = FilaMax;
}
int Items::GetIndiceColumna() {
	return IndiceColumna;
}
int Items::GetIndiceFila() {
	return IndiceFila;
}
int Items::GetFilaMax() {
	return FilaMax;
}
int Items::GetColumnaMax() {
	return ColumnaMax;
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
		IndiceColumna = 0;
	}
	if (tipo == 2)
	{
		IndiceColumna = 2;
	}

	if (tipo == 3)
	{
		IndiceColumna = 3;
	}
	if (tipo == 4)
	{
		IndiceColumna = 6;
	}
}
void Items::Dibujar(Graphics^ g, Image^ img) {
	Conf_tipo();
	l = img->Height / FilaMax;
	a = img->Width / ColumnaMax;
	Rectangle porcionUsar = Rectangle(IndiceColumna * a, IndiceFila * l, a, l);
	Rectangle Destino = Rectangle(x, y, a, l);
	if(!Eliminar)
	g->DrawImage(img, Destino, porcionUsar, GraphicsUnit::Pixel);
}
//void Items::Dibujar(System::Drawing::Graphics ^ g) {}