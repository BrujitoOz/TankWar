#pragma once
#include "Base.h"
class Torreta :
	public Base
{
	int IndiceColumna, IndiceFila, FilaMax, ColumnaMax, Vidas;
public:
	Torreta();
	~Torreta();

	void SetIndiceColumna(int IndiceColumna);
	void SetIndiceFila(int IndiceFila);
	void SetColumnaMax(int ColumnaMax);
	void SetFilaMax(int FilaMax);
	void SetVidas(int Vidas);
	int GetVidas();
	int GetIndiceColumna();
	int GetIndiceFila();
	int GetFilaMax();
	int GetColumnaMax();
	void Draw(Graphics^ g, Image^ img);

};

Torreta::Torreta()
{
	SetPathIMG("torretas.png");
	IndiceColumna = 0;
	IndiceFila = 0;
}


Torreta::~Torreta()
{
}
void Torreta::SetVidas(int Vidas)
{
	this->Vidas = Vidas;
}
int Torreta::GetVidas()
{
	return Vidas;
}
void Torreta::SetIndiceColumna(int IndiceColumna) {
	this->IndiceColumna = IndiceColumna;
}
void Torreta::SetIndiceFila(int IndiceFila) {
	this->IndiceFila = IndiceFila;
}
void Torreta::SetColumnaMax(int ColumnaMax) {
	this->ColumnaMax = ColumnaMax;
}
void Torreta::SetFilaMax(int FilaMax) {
	this->FilaMax = FilaMax;
}
int Torreta::GetIndiceColumna() {
	return IndiceColumna;
}
int Torreta::GetIndiceFila() {
	return IndiceFila;
}
int Torreta::GetFilaMax() {
	return FilaMax;
}
int Torreta::GetColumnaMax() {
	return ColumnaMax;
}
void Torreta::Draw(Graphics^ g, Image^ img) {
	if (!Eliminar)
	{
		l = img->Height / FilaMax;
		a = img->Width / ColumnaMax;
		Rectangle porcionUsar = Rectangle(IndiceColumna * a, IndiceFila * l, a, l);
		Rectangle Destino = Rectangle(x, y, a, l);
		g->DrawImage(img, Destino, porcionUsar, GraphicsUnit::Pixel);
	}
	
}