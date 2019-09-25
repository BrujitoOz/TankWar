#pragma once
#include "Base.h"
class Explocion :
	public Base
{
	int IndiceColumna, IndiceFila, FilaMax, ColumnaMax;

public:
	Explocion();
	~Explocion();
	void SetIndiceColumna(int IndiceColumna);
	void SetIndiceFila(int IndiceFila);
	void SetColumnaMax(int ColumnaMax);
	void SetFilaMax(int FilaMax);
	int GetIndiceColumna();
	int GetIndiceFila();
	int GetFilaMax();
	int GetColumnaMax();
	void Draw(Graphics^ g, Image^ img);
};


Explocion::Explocion()
{
	SetPathIMG("explociones.png");
	IndiceColumna = IndiceFila = 0;
}


Explocion::~Explocion()
{
}

void Explocion::SetIndiceColumna(int IndiceColumna) {
	this->IndiceColumna = IndiceColumna;
}
void Explocion::SetIndiceFila(int IndiceFila) {
	this->IndiceFila = IndiceFila;
}
void Explocion::SetColumnaMax(int ColumnaMax) {
	this->ColumnaMax = ColumnaMax;
}
void Explocion::SetFilaMax(int FilaMax) {
	this->FilaMax = FilaMax;
}
int Explocion::GetIndiceColumna() {
	return IndiceColumna;
}
int Explocion::GetIndiceFila() {
	return IndiceFila;
}
int Explocion::GetFilaMax() {
	return FilaMax;
}
int Explocion::GetColumnaMax() {
	return ColumnaMax;
}
void Explocion::Draw(Graphics^ g, Image^ img) {
	l = img->Height / FilaMax;
	a = img->Width / ColumnaMax;
	IndiceColumna++;
	if (IndiceColumna > 7) Eliminar = true; 
	Rectangle porcionUsar = Rectangle(IndiceColumna * a, IndiceFila * l, a, l);
	Rectangle Destino = Rectangle(x, y, a, l);
	if (!Eliminar)
		g->DrawImage(img, Destino, porcionUsar, GraphicsUnit::Pixel);
	// La funcion dibujar del tanque tambien dibuja sus balas

}