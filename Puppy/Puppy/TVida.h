#pragma once
#include "Base.h"
class TVida :
	public Base
{
	int IndiceColumna, IndiceFila, FilaMax, ColumnaMax;
public:
	TVida();
	~TVida();
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


TVida::TVida()
{
	SetPathIMG("TVida.png");
	IndiceColumna = IndiceFila = 0;
}
TVida::~TVida()
{
}
void TVida::SetIndiceColumna(int IndiceColumna) {
	this->IndiceColumna = IndiceColumna;
}
void TVida::SetIndiceFila(int IndiceFila) {
	this->IndiceFila = IndiceFila;
}
void TVida::SetColumnaMax(int ColumnaMax) {
	this->ColumnaMax = ColumnaMax;
}
void TVida::SetFilaMax(int FilaMax) {
	this->FilaMax = FilaMax;
}
int TVida::GetIndiceColumna() {
	return IndiceColumna;
}
int TVida::GetIndiceFila() {
	return IndiceFila;
}
int TVida::GetFilaMax() {
	return FilaMax;
}
int TVida::GetColumnaMax() {
	return ColumnaMax;
}
void TVida::Draw(Graphics^ g, Image^ img) {
	l = img->Height / FilaMax;
	a = img->Width / ColumnaMax;
	
	
	Rectangle porcionUsar = Rectangle(IndiceColumna * a, IndiceFila * l, a, l);
	Rectangle Destino = Rectangle(x, y, a, l);
	if (!Eliminar)
		g->DrawImage(img, Destino, porcionUsar, GraphicsUnit::Pixel);
	

}