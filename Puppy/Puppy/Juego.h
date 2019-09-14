#pragma once
#include "Player.h"
#include "Enemigo.h"
#include "Disco.h"
#include "Items.h"

enum direccion { arriba, abajo, izquierda, derecha, ninguno };
class Juego {
	Player* player;
	Enemigo* enemigo;
	Disco* disco;
public:
	Juego();
	~Juego();
	void Init();
	void Run(Graphics^ g, Image^ imgplayer, Image^ imgfondo);
	void Mover_player(direccion movimiento, Graphics^ g);
	bool Colision(Base* player, Base* disco);
};
Juego::Juego() {
}
Juego::~Juego() {
	delete player;
}
void Juego::Init() {
	player = new Player();
	player->SetX(500);
	player->SetY(300);
	String^ s = gcnew String(player->GetPathIMG());
	Image^ img = gcnew Bitmap(s);
	player->SetA(img->Width);
	player->SetL(img->Height);
	player->SetColumnaMax(4);
	player->SetFilaMax(4);

	enemigo = new Enemigo();
	enemigo->SetX(250);
	enemigo->SetY(500);
	enemigo->SetDX(14);
	enemigo->SetDY(0);
	enemigo->SetA(25);
	enemigo->SetL(25);

	disco = new Disco();
}
void Juego::Run(Graphics^ g, Image^ imgplayer, Image^ imgfondo) {
	//g->DrawImage(imgfondo, g->VisibleClipBounds);
	player->Draw(g, imgplayer);
	enemigo->Move(g);
	enemigo->Draw(g);
	int rmonedas = rand() % 30;
	disco->Draw(g);
	
		
		disco->SetX(rand() % 1500);
		disco->SetY(rand() % 800);
		disco->SetEliminar(false);
		disco->SetA(20);
		disco->SetL(12);


}
bool Juego::Colision(Base* player, Base* disco) {
	return 0;
}
void Juego::Mover_player(direccion movimiento, Graphics^ g) {
	if (movimiento == direccion::abajo)
		player->MoveDown(g);
	if (movimiento == direccion::arriba)
		player->MoveUp(g);
	if (movimiento == direccion::derecha)
		player->MoveRight(g);
	if (movimiento == direccion::izquierda)
		player->MoveLeft(g);
}