#pragma once
#include "Base.h"
class Player : public Base{
	int IndiceColumna, IndiceFila, FilaMax, ColumnaMax;
public:
	Player();
	~Player();

	void ShotPlayer();

	void SetIndiceColumna(int IndiceColumna);
	void SetIndiceFila(int IndiceFila);
	void SetColumnaMax(int ColumnaMax);
	void SetFilaMax(int FilaMax);
	int GetIndiceColumna();
	int GetIndiceFila();
	int GetFilaMax();
	int GetColumnaMax();
	void MoveUp(Graphics^ g);
	void MoveDown(Graphics^ g);
	void MoveRight(Graphics^ g);
	void MoveLeft(Graphics^ g);


	void Draw(Graphics^ g, Image^ img);
};
Player::Player() {
	SetPathIMG("tank.jpg");
	IndiceColumna = IndiceFila = 0;
}
Player::~Player() {
}
void ShotPlayer() {

	/*
	asegurarse que la cola este llena
	y buscar como disparar a la direccion donde apunta el tanque
	*/
}
void Player::MoveUp(Graphics^ g) {
	IndiceFila = 3;
	dy = -5;
	if (g->VisibleClipBounds.Top < (y + dy))
		y = y + dy;
	IndiceColumna++;
	if (IndiceColumna == 2)
		IndiceColumna = 0;
}
void Player::MoveDown(Graphics^ g) {
	IndiceFila = 0;
	dy = 5;
	if (g->VisibleClipBounds.Bottom > (y + dy + l))
		y = y + dy;
	IndiceColumna++;
	if (IndiceColumna == 2)
		IndiceColumna = 0;
}
void Player::MoveLeft(Graphics^ g) {
	IndiceFila = 1;
	dx = -5;
	if (g->VisibleClipBounds.Left < (x + dx))
		x = x + dx;
	IndiceColumna++;
	if (IndiceColumna == 2)
		IndiceColumna = 0;
}
void Player::MoveRight(Graphics^ g) {
	IndiceFila = 2;
	dx = 5;
	if (g->VisibleClipBounds.Right > (x + dx + a))
		x = x + dx;
	IndiceColumna++;
	if (IndiceColumna == 2)
		IndiceColumna = 0;
}
void Player::SetIndiceColumna(int IndiceColumna) { 
	this->IndiceColumna = IndiceColumna; 
}
void Player::SetIndiceFila(int IndiceFila) { 
	this->IndiceFila = IndiceFila; 
}
void Player::SetColumnaMax(int ColumnaMax) { 
	this->ColumnaMax = ColumnaMax; 
}
void Player::SetFilaMax(int FilaMax) { 
	this->FilaMax = FilaMax; 
}
int Player::GetIndiceColumna() { 
	return IndiceColumna; 
}
int Player::GetIndiceFila() { 
	return IndiceFila; 
}
int Player::GetFilaMax() { 
	return FilaMax; 
}
int Player::GetColumnaMax() { 
	return ColumnaMax; 
}
void Player::Draw(Graphics^ g, Image^ img) {
	l = img->Height / FilaMax;
	a = img->Width / ColumnaMax;
	Rectangle porcionUsar = Rectangle(IndiceColumna * a, IndiceFila * l, a, l);
	Rectangle Destino = Rectangle(x, y, a, l);
	g->DrawImage(img, Destino, porcionUsar, GraphicsUnit::Pixel);
}