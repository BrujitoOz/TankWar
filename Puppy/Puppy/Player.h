#pragma once
#include "Base.h"
#include "Queue.h"
#include "Bala.h"


class Player : public Base{
	int IndiceColumna, IndiceFila, FilaMax, ColumnaMax;

	LinkedQueue<Bala*> balas; // el player tiene una cola de balas
	Bala* currentBala; // variable que guardara la bala que se use


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

	void AddBala(int tipo) {
		Bala* bala = new Bala();
		bala->Cambiar_tipo(tipo); // la bala recibe el mismo "tipo" que tiene la clase Items, resultando que ambos tengan el mismo color
		bala->SetA(14); 
		bala->SetL(14);
		balas.push(bala); // se aniade a la cola

	}

	Bala* getCurrentBala() {
		return currentBala;
	}

    void removeCurrentBala();

};
Player::Player() {
	SetPathIMG("tank.jpg");
	IndiceColumna = IndiceFila = 0;
	currentBala = nullptr;
}
Player::~Player() {
}
void Player::ShotPlayer() {

	/*
	asegurarse que la cola este llena
	y buscar como disparar a la direccion donde apunta el tanque
	*/
	if (!balas.empty() && currentBala == nullptr)
	{
		currentBala = balas.pop(); // currentbala agarra la bala front de la cola
		currentBala->SetX(x+a/2); 
		currentBala->SetY(y+l/2);
		// se dispara en la direccion segun donde se encontraba apuntando el tanque como indica el sprite
		if (IndiceFila == 3)
		{
			currentBala->SetDX(0);
			currentBala->SetDY(-10);
		}


		if (IndiceFila == 0)
		{
			currentBala->SetDX(0);
			currentBala->SetDY(10);
		}

		if (IndiceFila == 1)
		{
			currentBala->SetDX(-10);
			currentBala->SetDY(0);
		}

		if (IndiceFila == 2)
		{
			currentBala->SetDX(10);
			currentBala->SetDY(0);
		}

	}

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
	// La funcion dibujar del tanque tambien dibuja sus balas
	if (currentBala != nullptr)
	{
		currentBala->Dibujar(g);
		bool eliminar = currentBala->Mover(g);

		if (eliminar)
		{
			removeCurrentBala(); // funcion para eliminar el currentbala
		}

	}
}


void Player::removeCurrentBala() {
	delete currentBala;
	currentBala = nullptr;
}


